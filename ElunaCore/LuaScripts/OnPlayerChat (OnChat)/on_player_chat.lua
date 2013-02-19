function chat_test(plr, type, lang, msg) -- Works perfectly
	if (msg == "test") then
	   print("chat_test::cmd::test")
	end
end

RegisterPlayerEvent(5, chat_test)