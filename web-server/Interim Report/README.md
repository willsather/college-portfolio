# Project 3 (Interim Report)
## Will Sather & Spencer Nelson

	Test Machine: 		csel-vole-29 (SATHE151)
	Date: 			12/9/2020
	x500: 			sathe151, nels9911
	Group: 			Project 4, Group 75

* **Interim Report**:
	- Attached to this interim report is a few items.  The first being our Util.c file with a completed init() method, completed accept_connection(), and a mostly completed get_request(). After that, there is a screenshot of the client connecting properly to the server and printing the request.  After this is turned in, we will attack the next portion of the project where we actually return the result or the error back to the client.  Lastly, the rest of this document is a portion of our readme that will be attached to the final project.  It contains what we have worked on currently, how we test/compile, and the importance of this project.  Thank you

* **How to Compile**:
  	- To compile Project 4, one must have the zipped directory somewhere in a Linux environment (Our group used a version of Ubuntu). Once the proper environment has been established, one can open two terminals and navigate to the directory where the program is stored in both. Then, for this to successfully run, one needs the proper permissions to the files and directory.  Once all of this can be confirmed, the program can be run using a normal "./web_server port path num_dispatch num_workers dynamic_flag qlen cache_entries" (ex. ./web_server 8151 home/Desktop/CSCI-4061/P3/testing 7 5 0 99 0). Once this process is open and running go into the second terminal (same directory) and enter the following command: "wget website" (ex. wget http://127.0.0.1:(Port Number from before goes here)/image/jpg/29.jpg.

* **What Does it Do**:
  	- This project opens a web server where there are different threads that read incoming websites or other file types. The work of analyzing these files are done by two types of threads (multiple of each type); dispatcher and worker threads. The dispatcher threads repeatedly accept an incoming connection, read the client request from the connection, and place the request in a queue. Then the worker threads then monitor the request queue, retrieve requests and serve the request’s results.  The primary amount of work required for this project is in the util file this time around.  

* **Outside Assumptions**:
  	- In order for this program to successfully run and operate, there are a few assumptions that must be made.  First, we are going to assume that the current and operating user has read and write security access to directory, and any related directories.  This program would fail if the operating system didn't allow the user to create new files and/or open said files.  Secondly, we are making the basic assumption that the user is using a compatible version of a Linux operating system, or UNIX compatible.  The C program and GCC compiler must be accessible and usable for the user and the current device.  

* **Member Contribution**:
	- Will Sather:
    > As far as distribution of work amongst the group, I took on the accept_connection and get_request methods, along with helping write the readme/interim report.  The accept connection method utilizes certain parts of the socket to accept a request to connect to the server, and then returns the file descriptor to the client.  This was cool to see how the backend of the server worked and we now know actually how the util.o file worked for us last time.  Secondly, I will be working on the get_request method.  Now that the interim report is complete, that is my next piece of work.   

  	- Spencer Nelson:
    > As far as what I did, I primarily took on writing the init method and some of get_request.  I also ended up doing a lot of testing debugging the entire project.  Will and I wrote a majority of the code together and took turns testing the project before the interim report is due.  So far, I also agree with Will and enjoy seeing how the backend of Util from project 3 was implemented and how we get to do it ourselves.  