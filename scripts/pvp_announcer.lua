local function PvPAnnouncer(event, killer, killed)
    SendWorldMessage("[PVP] |Hplayer:"..killer:GetName().."|h["..killer:GetName().."]|h killed |Hplayer:"..killed:GetName().."|h["..killed:GetName().."]|h")
end

RegisterPlayerEvent(6, PvPAnnouncer)
