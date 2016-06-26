local function NakedBugFix(event, player)
	if not (player:HasAura(54844)) then
		player:AddAura(54844, player)
		player:RemoveAura(54844)
	end
end

RegisterPlayerEvent(3, NakedBugFix)
RegisterPlayerEvent(27, NakedBugFix)
RegisterPlayerEvent(28, NakedBugFix)