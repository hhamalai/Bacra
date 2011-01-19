#include <QString>
#include <QtWebKit>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <QByteArray>
#include <QTextStream>
#include <QRegExpValidator>
#include <QRegExp>
#include "dataextractor.h"
#include "log.h"

bacra::DataExtractor::DataExtractor(QObject *parent) : QObject(parent), accessManager_(0), page_(0), jQuery_("")
{
    accessManager_ = new QNetworkAccessManager(this);

    connect(accessManager_, SIGNAL(finished(QNetworkReply*)), this,
            SLOT(handleOmatLahdotResponse(QNetworkReply*)));
}

bacra::DataExtractor::~DataExtractor(){
   delete this->accessManager_;
}

void bacra::DataExtractor::initialize(){
    this->loadScript(":/bacra/js/dataextraction/omatlahdot.js",omatLahdotJS_);
    this->loadScript(":/bacra/js/dataextraction/jquery-1.3.2.min.js",jQuery_);
}

void bacra::DataExtractor::servCallOmatLahdot(const QString &stopId){
    qDebug() << "bacra::DataExtractor::servCallOmatLahdot";
    this->accessManager_->get( QNetworkRequest(QUrl(QString("http://www.omatlahdot.fi/omatlahdot/web?stopid=%1&Submit=Hae&command=quicksearch&view=mobile").arg(stopId))));

}

void bacra::DataExtractor::servCallReittiOpas(const QString &, const QString &){

}

void bacra::DataExtractor::handleOmatLahdotResponse(QNetworkReply *reply){
    emit infoResponseReady(75);
    QByteArray bytes = reply->readAll();  // bytes
    qDebug() << "Got error" << reply->error();
    QString string(bytes); // string


    QWebPage page;
    page.mainFrame()->setHtml(string);



    bacra::Log::debugByRef(page.mainFrame()->title());
    page.mainFrame()->addToJavaScriptWindowObject("test",this);
    //ok here we insert the jQuery library into web page
    page.mainFrame()->evaluateJavaScript(jQuery_);



    /*
      ------------------------------------------------------
      Key idea is that we provide an interface which
      can be accessed trough javascript. Javascript
      jQuery does the heavy lifting of data and
      provides timetable data as string into our
      interface so we can process it further.

      we use evaluateJavaScript function to inject
      data into web page. In QT the web page is
      presented as QWebFrame

      This WebKit integration thing is quite cool!
      Application interoperability scenarios are
      numerous!!
      ------------------------------------------------------
     */

   // QString script2 = "var tmp = $('span[class=departures_title]').text()+';'; $('tr').each(function(i){$(this).find('td[class=departures_col_text]').each(function(j){ if($(this).attr('width') == '30%'){ tmp += $(this).text()+',';}if($(this).attr('width') == '20%'){tmp += $(this).text()+',';}if($(this).attr('width') == '50%'){tmp += $(this).text()+'#';}});}); test.testData(tmp);";
    //page.mainFrame()->evaluateJavaScript(script2);
    qDebug() <<  omatLahdotJS_.size();
    page.mainFrame()->evaluateJavaScript(omatLahdotJS_);

    //clear the reply because we own it
    //however documentation said that we shouldn't delete it...
    //delete reply;
    reply->deleteLater();
}

void bacra::DataExtractor::handleReittiopasResponse(QNetworkReply *){

}

void bacra::DataExtractor::loadScript(const QString &pathToScript, QString &loadTo){
    QFile file(pathToScript);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "Failed to open file " << pathToScript;
        return;
     }
     else{
        loadTo = file.readAll().trimmed();
        file.close();
     }
}

void bacra::DataExtractor::testData(QString const &data){

    qDebug() << "emitting data Received()" << data;
    QRegExp rx("\\S+;.+");
    QRegExpValidator v(rx, 0);
    QString s(data);
    int pos = 0;
    if (v.validate(s, pos) != QValidator::Invalid) {
        qDebug() << "invalid data from JS";
        emit invalidStopData();
        return;
    }
    emit stopDataReceived(data);
}
