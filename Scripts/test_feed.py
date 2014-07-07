import os
import feedparser

meetup_feed = feedparser.parse('http://www.meetup.com/Makespace/events/rss/')

buffer_name = meetup_feed.entries[0].title
buffer_desc = meetup_feed.entries[0].description

position_date_end = buffer_desc.rfind('M</p>') + 1
position_date_begin = buffer_desc.rfind('<p>',0,position_date_end) + 3

buffer_date = buffer_desc[position_date_begin:position_date_end]

buffer = """The next event is """ + buffer_name + """ on """ + buffer_date + """."""

#print buffer
os.system("""sudo write_disp -s 75 -m '""" + buffer + """'""")

