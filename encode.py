#!/usr/bin/python2
import sys

def decode_name(name):
	try:
		name = name.decode('utf8')
	except UnicodeDecodeError:
		name = name.decode('cp1251')
		pass

	return name


for name in sys.stdin:
	name = decode_name(name.strip())
	print "%s -> %s" % (name, name.encode('idna'))
