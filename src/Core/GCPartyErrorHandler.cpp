//////////////////////////////////////////////////////////////////////////////
// Filename    : GCPartyErrorHandler.cpp
// Written By  : �輺��
// Description :
//////////////////////////////////////////////////////////////////////////////

#include "GCPartyError.h"

void GCPartyErrorHandler::execute (GCPartyError * pPacket , Player * pPlayer)
	 throw(ProtocolException , Error)
{
	__BEGIN_TRY __BEGIN_DEBUG_EX
	
#ifdef __GAME_CLIENT__
	//cout << pPacket->toString() << endl;
#endif

	__END_DEBUG_EX __END_CATCH
}