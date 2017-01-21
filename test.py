__author__ = 'Shwetha'


from cloudant.client import Cloudant
import sys
import time
import serial
ser = serial.Serial('/dev/ttyACM0', 9600)


def commonCreation():
     global id,zipcode,rpino,statuss
     print "no docs"
     data = {
       '_id' : id,
       'zipcode' : zipcode,
       'pno' : rpino,
       'status' : statuss

         }
     return data

client = Cloudant('06867603-146b-43d1-b8d9-454f272fdc02-bluemix','cacca3cc252cb10645410c6e42a7ebb0c4a6382bb0dfa940b029d1de3285fa64',url='https://06867603-146b-43d1-b8d9-454f272fdc02-bluemix:cacca3cc252cb10645410c6e42a7ebb0c4a6382bb0dfa940b029d1de3285fa64@06867603-146b-43d1-b8d9-454f272fdc02-bluemix.cloudant.com')

# Connect to the server
client.connect()

# Perform client tasks...
session = client.session()


def update():
     if 'roo' in client.all_dbs():
          my_database = client['roo']
          selector = {'zipcode': zipcode,'pno':rpino,'_id':id}
          docs = my_database.get_query_result(selector,raw_result=True, limit=100)
          # print len(docs['docs'])
          if len(docs['docs']) == 0:
               # print "no docs"
               data = commonCreation()
               # Create a document using the Database API
               my_document = my_database.create_document(data)
          else:
               for doc in docs['docs']:
                    #  print "insidd docs"
                    my_doc=my_database[doc['_id']]
                    print my_doc['status'], statuss
                    if my_doc['status'] != statuss:
                         print "sadasd"
                         my_doc['status'] = statuss
                         my_doc.save()

     else:
          # print "there"
          my_database = client.create_database('roo')
          if my_database.exists():
               print 'Table creation SUCCESS!!'
               # Create document content data
          data = commonCreation()
          # Create a document using the Database API
          my_document = my_database.create_document(data)












while True:
    serInp =  ser.readline()
    print serInp
    inps = serInp.split("_")
    if len(inps) == 4:
         id = inps[1]
         zipcode = inps[3]
         rpino = inps[2]
         statuss = inps[0]
         update();
client.disconnect()         
