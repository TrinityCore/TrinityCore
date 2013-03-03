function OnEvents(evt, plr, arg1, _, msg) -- Works
    if (evt == 2) then
		print(plr:GetName().." killed "..arg1:GetName())
    elseif (evt == 16) then
	    if(msg == "test") then
			print("FUCKING CHAT")
		end
	elseif(evt == 27) then
		print("I FUCKING LEVELED BROH!")
	elseif (evt == 34) then
		print("TALENTS FUCKING CHANGED")
	end
end

--RegisterPlayerEvent(5, chat_test)

RegisterServerHook(2, OnEvents)
RegisterServerHook(16, OnEvents)
RegisterServerHook(27, OnEvents)
RegisterServerHook(34, OnEvents)