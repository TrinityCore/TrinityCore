function OnEvents(evt, plr, arg1, _, msg)
    if (evt == 2) then
        print(plr:GetName().." killed "..arg1:GetName())
    elseif (evt == 16) then
       if(msg == "test") then
           print("~OnCHAT~")
       end
    elseif(evt == 27) then
        print("Leveled Up!")
    elseif (evt == 34) then
        print("Talents Changed!")
    end
end

RegisterServerHook(2, OnEvents)
RegisterServerHook(16, OnEvents)
RegisterServerHook(27, OnEvents)
RegisterServerHook(34, OnEvents)