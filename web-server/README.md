# Project 3
## Will Sather & Spencer Nelson

	Test Machine: 		csel-vole-29 (SATHE151)
	Date: 			12/9/2020
	x500: 			sathe151, nels9911
	Group: 			Project 4, Group 75

* **Purpose**:
	- Purpose of this project is not only to utilize sockets to build the backend of our previous web server.  This is cool because we are expanding on our previous project and servers are prevelant all over the real world and computer engineering world.  These ideas are important when dealing with large amounts of data on a massive scale as a server is an infinite stream of files being sent.  Using sockets is important as well because of the level of safety required for letting in requests in your server.  Security is a massive concern today with all sorts of malicious attacks on computer servers and data centers.  

* **How to Compile**:
  	- To compile Project 4, one must have the zipped directory somewhere in a Linux environment (our group used a version of Ubuntu). Once the proper environment has been established, one can open two terminals and navigate to the directory where the program is stored in both. Then, for this to successfully run, one needs the proper permissions to the files and directory.  Once all of this can be confirmed, the program can be run using a normal "./web_server port path num_dispatch num_workers dynamic_flag qlen cache_entries" (ex. ./web_server 8151 home/Desktop/CSCI-4061/P3/testing 7 5 0 99 0). Once this process is open and running go into the second terminal (same directory) and enter the following command: "wget website" (ex. wget http://127.0.0.1:(Port Number from before goes here)/image/jpg/29.jpg.

* **What Does it Do**:
  	- This project opens a web server where there are different threads that read incoming websites or other file types. The work of analyzing these files are done by two types of threads (multiple of each type); dispatcher and worker threads. The dispatcher threads repeatedly accept an incoming connection, read the client request from the connection, and place the request in a queue. Then the worker threads then monitor the request queue, retrieve requests and serve the request’s results by returning it to the client.  The primary amount of work required for this project is in the util.c file this time around.  

* **Outside Assumptions**:
  	- In order for this program to successfully run and operate, there are a few assumptions that must be made.  First, we are going to assume that the current and operating user has read and write security access to directory, and any related directories.  This program would fail if the operating system didn't allow the user to create new files and/or open said files.  Secondly, we are making the basic assumption that the user is using a compatible version of a Linux operating system, or UNIX compatible.  The C program and GCC compiler must be accessible and usable for the user and the current device.  

* **Member Contribution**:
	- Will Sather:
    > As far as distribution of work amongst the group, I took on the accept_connection and the get_result methods, along with helping write the readme.  The accept connection method utilizes certain parts of the socket to accept a request to connect to the server, and then returns the file descriptor to the client.  This was cool to see how the backend of the server worked and we now know actually how the util.o file worked for us last time.  Secondly, I worked on the get_request method.  This was used by all the dispatcher threads to perform a HTTP GET request, again utilizing sockets and the file descriptors like mentioned above.  I also helped Spencer with miscellaneous work and most of the time we collaborated very closing contstantly discussing and working together.  

  	- Spencer Nelson:
    > As far as what I did, I primarily took on the other three methods Will didn't work on.  This consisted of starting with the init method.  I esssentially initalized the socket here ensuring the proper address, the necessary binding, and the ability to reuse the socket.  Also, I worked on the return_result which was almost strictly writing information to the socket descriptor.  Overall I worked on a lot of different aspects alongside Will and managed to get as much work done as we could.  I felt like I was able to apply, and learn, a lot of the skills required for socket and servers.  
