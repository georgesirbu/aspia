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

#include "crypto/message_decryptor_fake.h"

#include <cstring>

namespace crypto {

MessageDecryptorFake::MessageDecryptorFake() = default;

MessageDecryptorFake::~MessageDecryptorFake() = default;

size_t MessageDecryptorFake::decryptedDataSize(size_t in_size)
{
    return in_size;
}

bool MessageDecryptorFake::decrypt(const uint8_t* in, size_t in_size, uint8_t* out)
{
    memcpy(out, in, in_size);
    return true;
}

} // namespace crypto
