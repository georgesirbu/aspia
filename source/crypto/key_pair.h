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

#ifndef CRYPTO__KEY_PAIR_H
#define CRYPTO__KEY_PAIR_H

#include "base/macros_magic.h"
#include "base/memory/byte_array.h"
#include "crypto/openssl_util.h"

namespace crypto {

class KeyPair
{
public:
    KeyPair(KeyPair&& other) noexcept;
    KeyPair& operator=(KeyPair&& other) noexcept;
    ~KeyPair();

    enum class Type { X25519 };

    static KeyPair create(Type type);
    static KeyPair fromPrivateKey(const base::ByteArray& private_key);

    bool isValid() const;
    base::ByteArray privateKey() const;
    base::ByteArray publicKey() const;
    base::ByteArray sessionKey(const base::ByteArray& peer_public_key) const;

private:
    explicit KeyPair(EVP_PKEY_ptr&& pkey = nullptr) noexcept;

    EVP_PKEY_ptr pkey_;

    DISALLOW_COPY_AND_ASSIGN(KeyPair);
};

} // namespace crypto

#endif // CRYPTO__KEY_PAIR_H
