import os
import json
import urllib2

url = "http://datapoint.metoffice.gov.uk/public/data/val/wxfcs/all/json/310042?res=3hourly&key=d6d80975-b8f9-41e2-8e35-1d0bd08355db"

try:
  data = json.load(urllib2.urlopen(url))

  #print json.dumps(data, sort_keys=True, indent=2)

except (ValueError, KeyError, TypeError):
    print "JSON format error"


# need to create a list of weather types
# need to display the next (not current) forcast

# expand to tomorrows forcast too


buffer = """The weather forcast for """ + '0' + """ is """ + '0' + """."""

print buffer
#os.system("""sudo write_disp -s 75 -m '""" + buffer.encode("ascii", "ignore") + """'""")
