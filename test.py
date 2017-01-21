__author__ = 'Shwetha'


from cloudant.client import Cloudant

id = '013'
zipcode = "47408"
rpino = 32
statuss = 0


def commonCreation(my_document):
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
      print "updating from previous status of " + str(doc['status'])
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







for mydoc in my_database:


 # Display the document
 print mydoc.json()


client.disconnect()



