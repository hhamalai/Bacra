var tmp = $('span[class=departures_title]').text()+';'; 
	$('td[class=departures_col_text]').each(
		function(j){ 
			if($(this).attr('width') == '30%'){ 
				tmp += $(this).text()+',';
			}
			if($(this).attr('width') == '20%')
			{
				tmp += $(this).text()+',';
			}
			if($(this).attr('width') == '50%')
			{
				tmp += $(this).text()+'#';
			}
		});
test.testData(tmp);
