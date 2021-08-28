#pragma once

#include <vector>
#include <string>

#include "WebSocketServer.h"

class WebSocketSession;
typedef std::shared_ptr<WebSocketSession> SessionPtr;

namespace WebSocketProtocol {
	const std::vector<uint8_t> SupportedRpcVersions{
		1
	};

	struct ProcessResult {
		WebSocketServer::WebSocketCloseCode closeCode = WebSocketServer::WebSocketCloseCode::DontClose;
		std::string closeReason;
		json result;
	};

	void ProcessMessage(SessionPtr session, ProcessResult &ret, uint8_t opCode, json incomingMessage);
}
