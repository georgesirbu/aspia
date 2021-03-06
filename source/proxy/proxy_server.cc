//
// Aspia Project
// Copyright (C) 2020 Dmitry Chapyshev <dmitry@aspia.ru>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.
//

#include "proxy/proxy_server.h"

#include "net/network_channel.h"

namespace proxy {

Server::Server() = default;

Server::~Server() = default;

void Server::start()
{
    if (network_server_)
        return;

    network_server_ = std::make_unique<net::Server>();
    network_server_->start(0, this);
}

void Server::onNewConnection(std::unique_ptr<net::Channel> channel)
{
    // TODO
}

} // namespace proxy
