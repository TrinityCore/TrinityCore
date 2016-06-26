-- Allows running Eluna lua from ingame chat and from server console
-- This command is intended for development purposes
-- Example usage:
-- .eluna pp(GetLuaEngine(), "Code ran by:", plr and plr:GetName() or "console")

-- pp is defined to be a function to send a message to everyone on server and to console for easy printing
-- plr is the player using the command or nil if command from console
-- sel is the selection of plr or nil if nothing selected

-- errors in the lua code executed are printed to command invoker only (console or player), they are not logged
-- errors in timed events made with the code and such delayed actions are reported by normal means to the error logs and console if so defined in Eluna settings.

local runcmd = "eluna"
local mingmrank = 3
local function RunCommand(event, player, cmd)
    if ((not player or player:GetGMRank() >= mingmrank) and cmd:lower():find("^"..runcmd.." .+")) then
        -- Here you can define some environment variables for the code
        -- I defined plr to be the player or nil
        -- sel to be the current selection of the player or nil
        -- pp to print the passed arguments to everyone and to console
        local env = [[
            local plr = ...
            local sel = sel
            local pp = function(...)
                local t = {...}
                for i = 1, select("#", ...) do t[i] = tostring(t[i]) end
                local msg = table.concat(t, " ")
                SendWorldMessage(msg)
                print(msg)
            end
            if (plr) then
                sel = plr:GetSelection()
            end
        ]]
        local code = env..cmd:sub(#runcmd+2)
        local func, err = load(code, "."..runcmd)
        if (func) then
            local res
            res, err = pcall(func, player)
            if (res) then
                return false
            end
        end
        if (not player) then
            print(err)
        else
            player:SendBroadcastMessage(err)
        end
        return false
    end
end

RegisterPlayerEvent(42, RunCommand)
