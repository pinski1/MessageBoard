import os
import feedparser

d = feedparser.parse('http://open.live.bbc.co.uk/weather/feeds/en/2653941/3dayforecast.rss')

#print d.entries[0].title

buffer = """The weather forcast for today is """ + d.entries[0].description

os.system("""sudo write_disp -s 75 -m '""" + buffer.encode("ascii", "ignore") + """'""")
