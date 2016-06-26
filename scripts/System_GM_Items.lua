---by Kusanagy Azakura
-- Developers & Customizers WOW
 
 
local function GMItemLogin(event, player)
if player:GetGMRank() >= 1 then
                if (player:HasItem(2586, 1, 1)) then --  [Gamemaster's Robe]
                else
                        player:AddItem(2586, 1) --  [Gamemaster's Robe]
                                if (player:HasItem(11508, 1, 1)) then --  [Gamemaster's Slippers]
                                else
                                        player:AddItem(11508, 1) --  [Gamemaster's Slippers]
                                                if (player:HasItem(12064, 1, 1)) then --  [Gamemaster Hood]
                                                else
                                                        player:AddItem(12064, 1) --  [Gamemaster Hood]
                                                                if (player:HasItem(192, 1, 1)) then --  [Martin's Broken Staff]
                                                                else
                                                                        player:AddItem(192, 1) --  [Martin's Broken Staff]
                                                                                if (player:HasItem(22654, 1, 1)) then --  [Glacial Gloves]
                                                                                else
                                                                                        player:AddItem(22654, 1) --  [Glacial Gloves]
                                                                                                if (player:HasItem(22968, 1, 1)) then --  [Glacial Mantle]
                                                                                                else
                                                                                                        player:AddItem(22968, 1) --  [Glacial Mantle]
                                                                                                end
                                                                                                player:SendBroadcastMessage("|r|cff00ccffSystem |cffff0000[Game Master]|r")
                                                                                        end
                                                                                end
                                                                        end
                                                                end
                                                        end
                                                end
                                        end
                       
RegisterPlayerEvent(3, GMItemLogin)