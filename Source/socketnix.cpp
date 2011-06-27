/*
 GNU LESSER GENERAL PUBLIC LICENSE
 Version 3, 29 June 2007
 
 Copyright (C) 2007 Free Software Foundation, Inc. <http://fsf.org/>
 Everyone is permitted to copy and distribute verbatim copies
 of this license document, but changing it is not allowed.
 
 
 This version of the GNU Lesser General Public License incorporates
 the terms and conditions of version 3 of the GNU General Public
 License, supplemented by the additional permissions listed below.
 
 0. Additional Definitions.
 
 As used herein, "this License" refers to version 3 of the GNU Lesser
 General Public License, and the "GNU GPL" refers to version 3 of the GNU
 General Public License.
 
 "The Library" refers to a covered work governed by this License,
 other than an Application or a Combined Work as defined below.
 
 An "Application" is any work that makes use of an interface provided
 by the Library, but which is not otherwise based on the Library.
 Defining a subclass of a class defined by the Library is deemed a mode
 of using an interface provided by the Library.
 
 A "Combined Work" is a work produced by combining or linking an
 Application with the Library.  The particular version of the Library
 with which the Combined Work was made is also called the "Linked
 Version".
 
 The "Minimal Corresponding Source" for a Combined Work means the
 Corresponding Source for the Combined Work, excluding any source code
 for portions of the Combined Work that, considered in isolation, are
 based on the Application, and not on the Linked Version.
 
 The "Corresponding Application Code" for a Combined Work means the
 object code and/or source code for the Application, including any data
 and utility programs needed for reproducing the Combined Work from the
 Application, but excluding the System Libraries of the Combined Work.
 
 1. Exception to Section 3 of the GNU GPL.
 
 You may convey a covered work under sections 3 and 4 of this License
 without being bound by section 3 of the GNU GPL.
 
 2. Conveying Modified Versions.
 
 If you modify a copy of the Library, and, in your modifications, a
 facility refers to a function or data to be supplied by an Application
 that uses the facility (other than as an argument passed when the
 facility is invoked), then you may convey a copy of the modified
 version:
 
 a) under this License, provided that you make a good faith effort to
 ensure that, in the event an Application does not supply the
 function or data, the facility still operates, and performs
 whatever part of its purpose remains meaningful, or
 
 b) under the GNU GPL, with none of the additional permissions of
 this License applicable to that copy.
 
 3. Object Code Incorporating Material from Library Header Files.
 
 The object code form of an Application may incorporate material from
 a header file that is part of the Library.  You may convey such object
 code under terms of your choice, provided that, if the incorporated
 material is not limited to numerical parameters, data structure
 layouts and accessors, or small macros, inline functions and templates
 (ten or fewer lines in length), you do both of the following:
 
 a) Give prominent notice with each copy of the object code that the
 Library is used in it and that the Library and its use are
 covered by this License.
 
 b) Accompany the object code with a copy of the GNU GPL and this license
 document.
 
 4. Combined Works.
 
 You may convey a Combined Work under terms of your choice that,
 taken together, effectively do not restrict modification of the
 portions of the Library contained in the Combined Work and reverse
 engineering for debugging such modifications, if you also do each of
 the following:
 
 a) Give prominent notice with each copy of the Combined Work that
 the Library is used in it and that the Library and its use are
 covered by this License.
 
 b) Accompany the Combined Work with a copy of the GNU GPL and this license
 document.
 
 c) For a Combined Work that displays copyright notices during
 execution, include the copyright notice for the Library among
 these notices, as well as a reference directing the user to the
 copies of the GNU GPL and this license document.
 
 d) Do one of the following:
 
 0) Convey the Minimal Corresponding Source under the terms of this
 License, and the Corresponding Application Code in a form
 suitable for, and under terms that permit, the user to
 recombine or relink the Application with a modified version of
 the Linked Version to produce a modified Combined Work, in the
 manner specified by section 6 of the GNU GPL for conveying
 Corresponding Source.
 
 1) Use a suitable shared library mechanism for linking with the
 Library.  A suitable mechanism is one that (a) uses at run time
 a copy of the Library already present on the user's computer
 system, and (b) will operate properly with a modified version
 of the Library that is interface-compatible with the Linked
 Version.
 
 e) Provide Installation Information, but only if you would otherwise
 be required to provide such information under section 6 of the
 GNU GPL, and only to the extent that such information is
 necessary to install and execute a modified version of the
 Combined Work produced by recombining or relinking the
 Application with a modified version of the Linked Version. (If
 you use option 4d0, the Installation Information must accompany
 the Minimal Corresponding Source and Corresponding Application
 Code. If you use option 4d1, you must provide the Installation
 Information in the manner specified by section 6 of the GNU GPL
 for conveying Corresponding Source.)
 
 5. Combined Libraries.
 
 You may place library facilities that are a work based on the
 Library side by side in a single library together with other library
 facilities that are not Applications and are not covered by this
 License, and convey such a combined library under terms of your
 choice, if you do both of the following:
 
 a) Accompany the combined library with a copy of the same work based
 on the Library, uncombined with any other library facilities,
 conveyed under the terms of this License.
 
 b) Give prominent notice with the combined library that part of it
 is a work based on the Library, and explaining where to find the
 accompanying uncombined form of the same work.
 
 6. Revised Versions of the GNU Lesser General Public License.
 
 The Free Software Foundation may publish revised and/or new versions
 of the GNU Lesser General Public License from time to time. Such new
 versions will be similar in spirit to the present version, but may
 differ in detail to address new problems or concerns.
 
 Each version is given a distinguishing version number. If the
 Library as you received it specifies that a certain numbered version
 of the GNU Lesser General Public License "or any later version"
 applies to it, you have the option of following the terms and
 conditions either of that published version or of any later version
 published by the Free Software Foundation. If the Library as you
 received it does not specify a version number of the GNU Lesser
 General Public License, you may choose any version of the GNU Lesser
 General Public License ever published by the Free Software Foundation.
 
 If the Library as you received it specifies that a proxy can decide
 whether future versions of the GNU Lesser General Public License shall
 apply, that proxy's public statement of acceptance of any version is
 permanent authorization for you to choose that version for the
 Library.
 */
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <errno.h>
#include <time.h>
#include "socketNix.h"

using namespace std;

Socket::Socket() : m_sock(0) { }

Socket::~Socket() {
	if ( is_valid() )
		::close( m_sock );
}

bool Socket::create() {
	m_sock = ::socket(AF_INET,SOCK_STREAM,0);
	if (m_sock < 0) {
		throw SockExcept("Cant create socket!", CREATE_SOCK);
	}
	int y=1;
	setsockopt( m_sock, SOL_SOCKET,
               SO_REUSEADDR, &y, sizeof(int));   
	return true;
}

bool Socket::UDP_create() {
	m_sock = ::socket(PF_INET,SOCK_DGRAM,IPPROTO_UDP);
	if (m_sock < 0) {
		throw SockExcept("Error while creating socket!", WHILE_CREATE_SOCK);
	}
	return true;
}

bool Socket::bind( const int port ) {
	if ( ! is_valid() ) {
		return false;
	}
	m_addr.sin_family = AF_INET;
	m_addr.sin_addr.s_addr = INADDR_ANY;
	m_addr.sin_port = htons ( port );
	
	int bind_return = ::bind ( m_sock,
							  ( struct sockaddr * ) &m_addr, sizeof ( m_addr ) );
	if ( bind_return == -1 ) {
		return false;
	}
	return true;     
}

bool Socket::listen() const {
	if ( ! is_valid() ) {
		return false;
	}
	int listen_return = ::listen ( m_sock, MAXCONNECTIONS );
	if ( listen_return == -1 ) {
		return false;
	}
	return true;
}

bool Socket::accept ( Socket& new_socket ) const {
	int addr_length = sizeof ( m_addr );
	new_socket.m_sock = ::accept( m_sock,
								 ( sockaddr * ) &m_addr, ( socklen_t * ) &addr_length );
	if ( new_socket.m_sock <= 0 )
		return false;
	else
		return true;
}

bool Socket::connect( const string host, const int port ) {
	if ( ! is_valid() ) {
#ifdef DEBUG
		fprintf(stderr, "ERROR:  %s (%d)\n", strerror(errno), errno);
#endif
		return false;    
	}
	struct hostent *host_info;
	unsigned long addr;
	memset( &m_addr, 0, sizeof (m_addr));
	if ((addr = inet_addr( host.c_str() )) != INADDR_NONE) {
		memcpy( (char *)&m_addr.sin_addr,
               &addr, sizeof(addr));
	}
	else {
		host_info = gethostbyname( host.c_str() );
		if (NULL == host_info) {
			throw SockExcept("Unknown server/ip", UNKNOWN_SERVER);
		}
		memcpy( (char *)&m_addr.sin_addr, host_info->h_addr,
			   host_info->h_length);
	}
	m_addr.sin_family = AF_INET;
	m_addr.sin_port = htons( port );      
	
	int status = ::connect ( m_sock,
							( sockaddr * ) &m_addr, sizeof ( m_addr ) );
	
	if ( status == 0 ) {
		return true;
	} else {
#ifdef DEBUG
		fprintf(stderr, "ERROR:  %s (%d)\n", strerror(errno), errno);
#endif
		return false;
	}
}

bool Socket::send( const string s ) const {
	int status = ::send ( m_sock, s.c_str(), s.size(),  0 );
	if ( status == -1 ) {
		return false;
	} else {
		return true;
	}
}

int Socket::recv ( string& s ) const {
	char buf [ MAXRECV + 1 ];
	s = "";
	memset ( buf, 0, MAXRECV + 1 );
	
	int status = ::recv ( m_sock, buf, MAXRECV, 0 );
	if ( status > 0 || status != -1 ) {
		s = buf;
		return status;
	}
	else {
		throw SockExcept("Error within Socket::recv");
		return 0;
	} 
}

bool Socket::UDP_send( const string addr, const string s, const int port ) const {
	struct sockaddr_in addr_sento;
	struct hostent *h;
	int rc;
	
	h = gethostbyname(addr.c_str());
	if (h == NULL) {
		throw SockExcept("Unknown host/ip", UNKNOWN_SERVER);
	}
	
	addr_sento.sin_family = AF_INET;
	memcpy ( (char *) &addr_sento.sin_addr.s_addr,
            h->h_addr_list[0], h->h_length);
	addr_sento.sin_port = htons (port);
	rc = sendto( m_sock, s.c_str(), s.size(), 0,
				(struct sockaddr *) &addr_sento,
				sizeof (addr_sento));
	if (rc == -1) {
#ifdef DEBUG
		fprintf(stderr, "ERROR:  %s (%d)\n", strerror(errno), errno);
#endif
		throw SockExcept("Cant send data thru - sendto()",SEND_FAILED);
		
	}        
	return true;
}

int Socket::UDP_recv( string& s, int timeout ) {
	struct sockaddr_in addr_recvfrom;
	struct timeval tv;
	tv.tv_sec = timeout;  // timeout
	tv.tv_usec = 0;  
	int len, n;
	char buf [ MAXRECV + 1 ];
	s = "";
	
	setsockopt(m_sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv,sizeof(struct timeval));
	
	memset ( buf, 0, MAXRECV + 1 );
	len = sizeof (addr_recvfrom);

	n = recvfrom ( m_sock, buf, MAXRECV, 0,
					  (struct sockaddr *) &addr_recvfrom,
					  ( socklen_t * )&len );

	if (n == -1){
		throw SockExcept("No data", TIMEOUT);
		return 0;
	}
	else {
		s = buf;
		return n;
	} 
}

void Socket::cleanup() const { }

bool Socket::close() const {
	::close(m_sock);
	cleanup();
	return true;
}
