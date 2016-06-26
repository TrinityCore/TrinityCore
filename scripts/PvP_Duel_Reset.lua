function Player:ResetStuff()
    local pt = self:GetPowerType()
    
    self:ResetAllCooldowns()
    self:SetHealth(self:GetMaxHealth())
    self:SetPower(pt, self:GetMaxPower(pt))
end

function duelreset(event, winner, loser, type)
    winner:ResetStuff()
    loser:ResetStuff()
end

RegisterPlayerEvent(11, duelreset)