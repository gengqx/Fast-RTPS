// Copyright 2016 Proyectos y Sistemas de Mantenimiento SL (eProsima).
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _UNITTEST_SECURITY_AUTHENTICATION_AUTHENTICATIONPLUGINTESTS_HPP_
#define _UNITTEST_SECURITY_AUTHENTICATION_AUTHENTICATIONPLUGINTESTS_HPP_

#include "../../../../src/cpp/rtps/security/SecurityPluginFactory.h"

#include <gtest/gtest.h>

using namespace eprosima::fastrtps::rtps;
using namespace ::security;

class AuthenticationPluginTest : public ::testing::Test
{
    protected:

        virtual void SetUp()
        {
            plugin = factory.create_authentication_plugin(property_policy);
        }

        virtual void TearDown()
        {
            delete plugin;
        }

    public:

        AuthenticationPluginTest() : plugin(nullptr){}

        SecurityPluginFactory factory;
        Authentication* plugin;

        static PropertyPolicy property_policy;
};

PropertyPolicy AuthenticationPluginTest::property_policy;

TEST_F(AuthenticationPluginTest, validate_local_identity_validation_ok)
{
    ASSERT_TRUE(plugin != nullptr);

    IdentityHandle* local_identity_handle = nullptr;
    GUID_t adjusted_participant_key;
    uint32_t domain_id = 0;
    RTPSParticipantAttributes participant_attr;
    GUID_t candidate_participant_key;
    SecurityException exception;
    ValidationResult_t result= ValidationResult_t::VALIDATION_FAILED;

    result = plugin->validate_local_identity(&local_identity_handle,
            adjusted_participant_key,
            domain_id,
            participant_attr,
            candidate_participant_key,
            exception);

    ASSERT_TRUE(result == ValidationResult_t::VALIDATION_OK);
}

#endif // _UNITTEST_SECURITY_AUTHENTICATION_AUTHENTICATIONPLUGINTESTS_HPP_