local ZoneCheck = {
        AllowedZones = {
				[12] = true,
        },
        TeleportLocations = {
                -- [TeamId] = {Map, X, Y, Z, Orientation}
                [0] = {0, -9483, 139, 57, 0},
                [1] = {0, -9410, 16, 61, 0},
        },
        RestrictedMessage = "You have entered a restricted zone. You have been removed from the area."
}
 
function ZoneCheck.OnChange(event, player, newZone)
        if not player:IsGM() then
                if not(ZoneCheck.AllowedZones[newZone]) then
                        local map, x, y, z, o = table.unpack(ZoneCheck.TeleportLocations[player:GetTeam()])
                        player:Teleport(map, x, y, z, o)
                        player:SendAreaTriggerMessage(ZoneCheck.RestrictedMessage)
                end
        end
end
 
RegisterPlayerEvent(27, ZoneCheck.OnChange)