import os

misc_sayings_obj = open('misc_sayings.txt', 'r')

for line in misc_sayings_obj:
 
  # need a way to escape non-text characters
  buffer = """sudo write_disp -s 25 -m '""" + line + """'"""

  os.system(buffer),
