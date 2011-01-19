#ifndef DATAEXTRACTOR_H
#define DATAEXTRACTOR_H


#include <QWidget>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QWebPage>

    ////////////////////////////////////////////////////////////
    // Class representing extractor which extracts data from
    // HKL route services (www.omatlahdot.fi & www.reittiopas.fi)
    //
    // Purpose of this class is to populate and create new route
    // objects from data. It seems that we need to do some kind
    // of callback thing to extract data from HTTP response.
    //
namespace bacra{
    class DataExtractor : public QObject
    {
        Q_OBJECT

        public:

            DataExtractor(QObject *parent = 0);
            ~DataExtractor();

            ////////////////////////////////////////////////////////////
            // Call this after constructor has been called. It loads
            // jQuery.
            //
            void initialize();

            ////////////////////////////////////////////////////////////
            // Call to HKL www.omatlahdot.fi service.
            // HTTP GET call goes to following URL
            // http://www.omatlahdot.fi/omatlahdot/web?
            //
            // Service uses following parameters:
            //
            // [stopid] = number of stop
            // [Submit] = Hae
            // [command] = quicksearch
            // [view] = mobile
            //
            // param: stopId - number of stop
            // return TODO
            //
            void servCallOmatLahdot(const QString &stopId);

            ////////////////////////////////////////////////////////////
            // Call to HKL www.reittiopas.fi service.
            //
            //
            void servCallReittiOpas(QString const &startStop,  QString const &endStop);

        signals:
            void infoResponseReady(int);
            void stopDataReceived(const QString &);
            void invalidStopData();

        public slots:

            void testData(QString const &data);

        private:
            ////////////////////////////////////////////////////////////
            // Prevent copy constructing
            //
            DataExtractor(const DataExtractor&);

            ////////////////////////////////////////////////////////////
            // Prevent default assignment
            //
            DataExtractor &operator = (const DataExtractor&);

            ////////////////////////////////////////////////////////////
            // Loads given javascript to given variable
            //
            void loadScript(const QString &pathToScript, QString &loadTo);

            QNetworkAccessManager *accessManager_;
            QWebPage *page_;
            QString jQuery_;
            QString omatLahdotJS_;
            QString reittiOpasJS_;


        private slots:

            void handleOmatLahdotResponse(QNetworkReply *reply);
            void handleReittiopasResponse(QNetworkReply *reply);


    };
}
#endif // DATAEXTRACTOR_H
