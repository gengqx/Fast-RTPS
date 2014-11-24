/*************************************************************************
 * Copyright (c) 2014 eProsima. All rights reserved.
 *
 * This copy of eProsima RTPS is licensed to you under the terms described in the
 * fastrtps_LIBRARY_LICENSE file included in this distribution.
 *
 *************************************************************************/

/**
 * @file UnsentChangesNotEmptyEvent.h
 *
 */

#ifndef UNSENTCHANGESNOTEMPTYEVENT_H_
#define UNSENTCHANGESNOTEMPTYEVENT_H_

#include "fastrtps/rtps/resources/TimedEvent.h"

namespace eprosima {
namespace fastrtps{
namespace rtps {

class RTPSWriter;

class UnsentChangesNotEmptyEvent: public TimedEvent {
public:
	UnsentChangesNotEmptyEvent(RTPSWriter* writer,double interval);
	virtual ~UnsentChangesNotEmptyEvent();

	void event(EventCode code, const char* msg= nullptr);

	RTPSWriter* mp_writer;
};
}
} /* namespace rtps */
} /* namespace eprosima */

#endif /* UNSENTCHANGESNOTEMPTYEVENT_H_ */