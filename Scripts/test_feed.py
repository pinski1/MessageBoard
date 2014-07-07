import os
import json
import urllib2

# using the Meetup API get the JSON file of the next event

url = "http://api.meetup.com/2/events?status=upcoming&order=time&limited_events=False&group_urlname=Makespace&desc=false&offset=0&photo-host=public&format=json&page=2&fields=&sig_id=128594992&sig=32c1fc602f75189fdc9119b7dc457f3f315a6f3f"

try:
  data = json.load(urllib2.urlopen(url))

  print json.dumps(data, sort_keys=True, indent=2)

except (ValueError, KeyError, TypeError):
    print "JSON format error"


  

#buffer = """The next event is """ + buffer_name + """ on """ + buffer_date + """."""

#print data
#os.system("""sudo write_disp -s 75 -m '""" + buffer + """'""")

