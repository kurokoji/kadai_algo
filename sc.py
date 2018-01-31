import pandas

url = 'http://www.sanspo.com/baseball/professional/player/dragons/player.html'
fetched_dataframes = pandas.io.html.read_html(url)
fetched_dataframes[0].to_csv('dragons.csv')
