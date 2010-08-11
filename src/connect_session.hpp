/*
    Copyright (c) 2007-2010 iMatix Corporation

    This file is part of 0MQ.

    0MQ is free software; you can redistribute it and/or modify it under
    the terms of the Lesser GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    0MQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    Lesser GNU General Public License for more details.

    You should have received a copy of the Lesser GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __ZMQ_CONNECT_SESSION_HPP_INCLUDED__
#define __ZMQ_CONNECT_SESSION_HPP_INCLUDED__

#include <string>

#include "session.hpp"

namespace zmq
{

    //  Connect session contains an address to connect to. On disconnect it
    //  attempts to reconnect.

    class connect_session_t : public session_t
    {
    public:

        connect_session_t (class io_thread_t *io_thread_,
            class socket_base_t *socket_, const options_t &options_,
            const char *protocol_, const char *address_);
        ~connect_session_t ();

        //  i_inout interface implementation.
        void detach ();

    private:

        //  Start the connection process.
        void start_connecting ();

        //  Command handlers.
        void process_plug ();

        //  Address to connect to.
        std::string protocol;
        std::string address;
    };

}

#endif
