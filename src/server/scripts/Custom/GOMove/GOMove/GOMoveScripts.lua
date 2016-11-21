GOMove.FavL = {NameWidth = 17}
function GOMove.FavL:Add(name, guid)
    self:Del(guid)
    table.insert(self, 1, {name, guid})
    GOMoveSV.FavL = self
end
function GOMove.FavL:Del(guid)
    for k,v in ipairs(self) do
        if(v[2] == guid) then
            table.remove(self, k)
            break
        end
    end
    GOMoveSV.FavL = self
end

GOMove.SelL = {NameWidth = 17}
function GOMove.SelL:Add(name, guid, entry)
    table.insert(self, 1, {name, guid, entry})
end
function GOMove.SelL:Del(guid)
    for k,v in ipairs(self) do
        if(v[2] == guid) then
            table.remove(self, k)
            break
        end
    end
end

GOMove.Selected = {}
function GOMove.Selected:Add(name, guid)
    self[guid] = name
end
function GOMove.Selected:Del(guid)
    self[guid] = nil
end

-- FAVOURITE LIST
local FavFrame = GOMove:CreateFrame("Favourite_List", 200, 280, GOMove.FavL, true)
FavFrame:Position("BOTTOMRIGHT", UIParent, "BOTTOMRIGHT", 0, 0)
function FavFrame:ButtonOnClick(ID)
    GOMove:Move("SPAWN", self.DataTable[FauxScrollFrame_GetOffset(self.ScrollBar) + ID][2])
end
function FavFrame:MiscOnClick(ID)
    self.DataTable:Del(self.DataTable[FauxScrollFrame_GetOffset(self.ScrollBar) + ID][2])
    self:Update()
end

-- SELECTION LIST
local SelFrame = GOMove:CreateFrame("Selection_List", 250, 280, GOMove.SelL, true)
SelFrame:Position("BOTTOMRIGHT", FavFrame, "TOPRIGHT", 0, 0)
function SelFrame:ButtonOnClick(ID)
    local DATAID = FauxScrollFrame_GetOffset(self.ScrollBar) + ID
    if(GOMove.Selected[self.DataTable[DATAID][2]]) then
        GOMove.Selected:Del(self.DataTable[DATAID][2])
    else
        GOMove.Selected:Add(self.DataTable[DATAID][1], self.DataTable[DATAID][2])
    end
    self:Update()
end
function SelFrame:MiscOnClick(ID)
    local DATAID = FauxScrollFrame_GetOffset(self.ScrollBar) + ID
    GOMove.Selected:Del(self.DataTable[DATAID][2])
    self.DataTable:Del(self.DataTable[DATAID][2])
    self:Update()
end
function SelFrame:UpdateScript(ID)
    local DATAID = FauxScrollFrame_GetOffset(self.ScrollBar) + ID
    if(self.DataTable[DATAID]) then
        if(GOMove.Selected[self.DataTable[DATAID][2]]) then
            self.Buttons[ID]:GetFontString():SetTextColor(1, 0.8, 0)
        else
            self.Buttons[ID]:GetFontString():SetTextColor(1, 1, 1)
        end
    end
end
local ClearButton = CreateFrame("Button", SelFrame:GetName().."_ToggleSelect", SelFrame)
ClearButton:SetSize(16, 16)
ClearButton:SetNormalTexture("Interface\\Buttons\\UI-GuildButton-PublicNote-Disabled")
ClearButton:SetPushedTexture("Interface\\Buttons\\UI-GuildButton-OfficerNote-Up")
ClearButton:SetHighlightTexture("Interface\\Buttons\\UI-GuildButton-PublicNote-Up")
ClearButton:SetPoint("TOPRIGHT", SelFrame, "TOPRIGHT", -30, -5)
ClearButton:SetScript("OnClick", function()
    local empty = true
    for k,v in pairs(GOMove.Selected) do
        if(tonumber(k)) then
            empty = false
        end
    end
    if(empty) then
        for k, tbl in ipairs(SelFrame.DataTable) do
            GOMove.Selected:Add(tbl[1], tbl[2])
        end
    else
        for k,v in pairs(GOMove.Selected) do
            if(tonumber(k)) then
                GOMove.Selected:Del(k)
            end
        end
    end
    SelFrame:Update()
end)
for i = 1, SelFrame.ButtonCount do
    local Button = SelFrame.Buttons[i]
    local MiscButton = Button.MiscButton
    local FavButton = CreateFrame("Button", Button:GetName().."_Favourite", MiscButton)
    FavButton:SetSize(16, 16)
    FavButton:SetNormalTexture("Interface\\Buttons\\UI-PlusButton-Up")
    FavButton:SetPushedTexture("Interface\\Buttons\\UI-PlusButton-Down")
    FavButton:SetHighlightTexture("Interface\\Buttons\\UI-PlusButton-Hilighted")
    FavButton:SetPoint("TOPRIGHT", MiscButton, "TOPLEFT", 0, 0)
    FavButton:SetScript("OnClick", function()
        local DATAID = FauxScrollFrame_GetOffset(SelFrame.ScrollBar) + i
        FavFrame.DataTable:Add(SelFrame.DataTable[DATAID][1], SelFrame.DataTable[DATAID][3])
        FavFrame:Update()
    end)
    local DeleteButton = CreateFrame("Button", Button:GetName().."_Delete", FavButton)
    DeleteButton:SetSize(16, 16)
    DeleteButton:SetNormalTexture("Interface\\PaperDollInfoFrame\\SpellSchoolIcon5")
    DeleteButton:SetPushedTexture("Interface\\PaperDollInfoFrame\\SpellSchoolIcon7")
    DeleteButton:SetHighlightTexture("Interface\\PaperDollInfoFrame\\SpellSchoolIcon3")
    DeleteButton:SetPoint("TOPRIGHT", FavButton, "TOPLEFT", 0, 0)
    DeleteButton:SetScript("OnClick", function()
        GOMove:Move("DELETE", SelFrame.DataTable[FauxScrollFrame_GetOffset(SelFrame.ScrollBar) + i][2])
    end)
    local SpawnButton = CreateFrame("Button", Button:GetName().."_Spawn", DeleteButton)
    SpawnButton:SetSize(16, 16)
    SpawnButton:SetNormalTexture("Interface\\Buttons\\UI-SpellbookIcon-PrevPage-Disabled")
    SpawnButton:SetPushedTexture("Interface\\Buttons\\UI-SpellbookIcon-PrevPage-Down")
    SpawnButton:SetHighlightTexture("Interface\\Buttons\\UI-SpellbookIcon-PrevPage-Up")
    SpawnButton:SetPoint("TOPRIGHT", DeleteButton, "TOPLEFT", 0, 0)
    SpawnButton:SetScript("OnClick", function()
        GOMove:Move("RESPAWN", SelFrame.DataTable[FauxScrollFrame_GetOffset(SelFrame.ScrollBar) + i][2])
    end)
end
local EmptyButton = CreateFrame("Button", SelFrame:GetName().."_EmptyButton", SelFrame)
EmptyButton:SetSize(30, 30)
EmptyButton:SetNormalTexture("Interface\\Buttons\\CancelButton-Up")
EmptyButton:SetPushedTexture("Interface\\Buttons\\CancelButton-Down")
EmptyButton:SetHighlightTexture("Interface\\Buttons\\CancelButton-Highlight")
EmptyButton:SetPoint("TOPRIGHT", SelFrame, "TOPRIGHT", -45, 0)
EmptyButton:SetHitRectInsets(9, 7, 7, 10)
EmptyButton:SetScript("OnClick", function()
    for k,v in pairs(GOMove.Selected) do
        if(tonumber(k)) then
            GOMove.Selected:Del(k)
        end
    end
    for i = #SelFrame.DataTable, 1, -1 do
        SelFrame.DataTable:Del(SelFrame.DataTable[i][2])
    end
    SelFrame:Update()
end)

-- MAIN FRAME
local MainFrame = GOMove:CreateFrame("GOMove_UI", 170, 455)
GOMove.MainFrame = MainFrame
MainFrame:Position("LEFT", UIParent, "LEFT", 0, 85)

local NEWS = GOMove:CreateInput(MainFrame, "NEWS", 40, 25, 0, -50, 4, 30)

local NORTH = GOMove:CreateButton(MainFrame, "N", 50, 25, 0, -25)
function NORTH:OnClick()
    GOMove:Move("NORTH", NEWS:GetNumber())
end
local EAST = GOMove:CreateButton(MainFrame, "E", 50, 25, 50, -50)
function EAST:OnClick()
    GOMove:Move("EAST", NEWS:GetNumber())
end
local SOUTH = GOMove:CreateButton(MainFrame, "S", 50, 25, 0, -75)
function SOUTH:OnClick()
    GOMove:Move("SOUTH", NEWS:GetNumber())
end
local WEST = GOMove:CreateButton(MainFrame, "W", 50, 25, -50, -50)
function WEST:OnClick()
    GOMove:Move("WEST", NEWS:GetNumber())
end

local NORTHEAST = GOMove:CreateButton(MainFrame, "NE", 40, 20, 45, -30)
function NORTHEAST:OnClick()
    GOMove:Move("NORTHEAST", NEWS:GetNumber())
end
local NORTHWEST = GOMove:CreateButton(MainFrame, "NW", 40, 20, -45, -30)
function NORTHWEST:OnClick()
    GOMove:Move("NORTHWEST", NEWS:GetNumber())
end
local SOUTHEAST = GOMove:CreateButton(MainFrame, "SE", 40, 20, 45, -75)
function SOUTHEAST:OnClick()
    GOMove:Move("SOUTHEAST", NEWS:GetNumber())
end
local SOUTHWEST = GOMove:CreateButton(MainFrame, "SW", 40, 20, -45, -75)
function SOUTHWEST:OnClick()
    GOMove:Move("SOUTHWEST", NEWS:GetNumber())
end

local X = GOMove:CreateButton(MainFrame, "X", 35, 20, -60, -105)
function X:OnClick()
    GOMove:Move("X")
end
local Y = GOMove:CreateButton(MainFrame, "Y", 35, 20, -20, -105)
function Y:OnClick()
    GOMove:Move("Y")
end
local Z = GOMove:CreateButton(MainFrame, "Z", 35, 20, 20, -105)
function Z:OnClick()
    GOMove:Move("Z")
end
local O = GOMove:CreateButton(MainFrame, "O", 35, 20, 60, -105)
function O:OnClick()
    GOMove:Move("O")
end

local ROTHEI = GOMove:CreateInput(MainFrame, "ROTHEI", 40, 25, 0, -155, 4, 30)
local UP = GOMove:CreateButton(MainFrame, "Up", 40, 25, 0, -130)
function UP:OnClick()
    GOMove:Move("UP", ROTHEI:GetNumber())
end
local DOWN = GOMove:CreateButton(MainFrame, "Down", 40, 25, 0, -180)
function DOWN:OnClick()
    GOMove:Move("DOWN", ROTHEI:GetNumber())
end
local RIGHT = GOMove:CreateButton(MainFrame, "Right", 40, 25, 45, -155)
function RIGHT:OnClick()
    GOMove:Move("RIGHT", ROTHEI:GetNumber())
end
local LEFT = GOMove:CreateButton(MainFrame, "Left", 40, 25, -45, -155)
function LEFT:OnClick()
    GOMove:Move("LEFT", ROTHEI:GetNumber())
end

local RESPAWN = GOMove:CreateButton(MainFrame, "Respawn", 65, 25, -35, -237.5)
function RESPAWN:OnClick()
    GOMove:Move("RESPAWN")
end
local FLOOR = GOMove:CreateButton(MainFrame, "Floor", 65, 25, 35, -237.5)
function FLOOR:OnClick()
    GOMove:Move("FLOOR")
end
local SELECTNEAR = GOMove:CreateButton(MainFrame, "Target", 50, 25, 55, -210)
function SELECTNEAR:OnClick()
    GOMove:Move("SELECTNEAR")
end
local FACE = GOMove:CreateButton(MainFrame, "Snap", 50, 25, 0, -210)
function FACE:OnClick()
    GOMove:Move("FACE")
end
local DELETE = GOMove:CreateButton(MainFrame, "Delete", 50, 25, -55, -210)
function DELETE:OnClick()
    GOMove:Move("DELETE")
end

local GROUND = GOMove:CreateButton(MainFrame, "Ground", 70, 25, -40, -265)
function GROUND:OnClick()
    GOMove:Move("GROUND")
end
local GOTO = GOMove:CreateButton(MainFrame, "Go to", 70, 25, 40, -265)
function GOTO:OnClick()
    GOMove:Move("GOTO")
end

local ENTRY = GOMove:CreateInput(MainFrame, "ENTRY", 65, 25, -30, -295, 10)
local SPAWN = GOMove:CreateButton(MainFrame, "Spawn", 50, 25, 40, -295)
function SPAWN:OnClick()
    GOMove:Move("SPAWN", ENTRY:GetNumber())
end

local RADIUS = GOMove:CreateInput(MainFrame, "RADIUS", 40, 25, -55, -325, 4)
local SELECTALLNEAR = GOMove:CreateButton(MainFrame, "Select by radius", 110, 25, 25, -325)
function SELECTALLNEAR:OnClick()
    GOMove:Move("SELECTALLNEAR", RADIUS:GetNumber())
end

local MASK = GOMove:CreateInput(MainFrame, "MASK", 65, 25, -30, -355, 10)
local PHASE = GOMove:CreateButton(MainFrame, "Phase", 50, 25, 40, -355)
function PHASE:OnClick()
    GOMove:Move("PHASE", MASK:GetNumber())
end

local FAVOURITES = GOMove:CreateButton(MainFrame, "Favourites", 80, 25, -40, -385)
function FAVOURITES:OnClick()
    if(FavFrame:IsVisible()) then
        FavFrame:Hide()
    else
        FavFrame:Show()
    end
end
local SELECTIONS = GOMove:CreateButton(MainFrame, "Selections", 80, 25, 40, -385)
function SELECTIONS:OnClick()
    if(SelFrame:IsVisible()) then
        SelFrame:Hide()
    else
        SelFrame:Show()
    end
end

local SPELLENTRY = GOMove:CreateInput(MainFrame, "SPELLENTRY", 65, 25, -30, -415, 10)
local SPELLSPAWN = GOMove:CreateButton(MainFrame, "Send", 50, 25, 40, -415)
function SPELLSPAWN:OnClick()
    GOMove:Move("SPAWNSPELL", SPELLENTRY:GetNumber())
end

GOMove.SCMD = {}
function GOMove.SCMD.help()
    for k, v in pairs(GOMove.SCMD) do
        print(k)
    end
end
function GOMove.SCMD.reset()
    for k, inputfield in ipairs(GOMove.Inputs) do
        inputfield:ClearFocus()
    end
    print("Frames reset")
    for k, Frame in pairs(GOMove.Frames) do
        if(Frame.Default) then
            Frame:ClearAllPoints()
            Frame:SetPoint(Frame.Default[1], Frame.Default[2], Frame.Default[3], Frame.Default[4], Frame.Default[5])
        end
        Frame:Show()
    end
end
function GOMove.SCMD.invertselection()
    local sel = {}
    for GUID, NAME in pairs(GOMove.Selected) do
        if(tonumber(GUID)) then
            table.insert(sel, GUID)
        end
    end
    for k, tbl in ipairs(SelFrame.DataTable) do
        GOMove.Selected:Add(tbl[1], tbl[2])
    end
    for k,v in ipairs(sel) do
        GOMove.Selected:Del(v)
    end
    SelFrame:Update()
end

SLASH_GOMOVE1 = '/gomove'
function SlashCmdList.GOMOVE(msg, editBox)
    if(msg ~= '') then
        for k, v in pairs(GOMove.SCMD) do
            if(type(k) == "string" and string.find(k, msg:lower()) == 1 and type(v) == "function") then
                v()
                break;
            end
        end
        return
    end
    if(MainFrame:IsVisible()) then
        MainFrame:Hide()
    else
        MainFrame:Show()
    end
end

local EventFrame = CreateFrame("Frame")
EventFrame:RegisterEvent("ADDON_LOADED")
EventFrame:RegisterEvent("CHAT_MSG_ADDON")

EventFrame:SetScript("OnEvent",
    function(self, event, MSG, MSG2, Type, Sender)
        if(event == "CHAT_MSG_ADDON" and Sender == UnitName("player")) then
            if MSG ~= "GOMOVE" then return end
            local ID, ENTRYORGUID, ARG2, ARG3 = MSG2:match("^(.+)|([%a%d]+)|(.*)|([%a%d]+)$")
            if(ID) then
                --if(ID == "USED") then
                --    for k,v in ipairs(GOMove.UseL) do
                --        if(ENTRYORGUID == v[2]) then
                --            return
                --        end
                --    end
                --    GOMove.UseL:Add(ARG2, ENTRYORGUID)
                --    GOMove:Update()
                if(ID == "REMOVE") then
                    local guid = ENTRYORGUID
                    GOMove.Selected:Del(guid)
                    for k,tbl in ipairs(GOMove.SelL) do
                        if(tbl[2] == guid) then
                            GOMove.SelL:Del(guid)
                            break
                        end
                    end
                    GOMove:Update()
                elseif(ID == "ADD") then
                    local guid = ENTRYORGUID
                    GOMove.Selected:Add(ARG2, guid)
                    local exists = false
                    for k, tbl in ipairs(GOMove.SelL) do
                        if(tbl[2] == guid) then
                            exists = true
                            break
                        end
                    end
                    if(not exists) then
                        GOMove.SelL:Add(ARG2, guid, ARG3)
                    end
                    GOMove:Update()
                elseif(ID == "SWAP") then
                    local oldGUID, newGUID = ENTRYORGUID, ARG3
                    GOMove.Selected:Add(GOMove.Selected[oldGUID], newGUID)
                    GOMove.Selected:Del(oldGUID)
                    for k,tbl in ipairs(GOMove.SelL) do
                        if(tbl[2] == oldGUID) then
                            tbl[2] = newGUID
                            break
                        end
                    end
                    GOMove:Update()
                end
            end
        elseif(MSG == "GOMove" and event == "ADDON_LOADED") then
            if(not GOMoveSV or type(GOMoveSV) ~= "table") then
                GOMoveSV = {}
            end
            if(GOMoveSV.FavL) then
                for k,v in ipairs(GOMoveSV.FavL) do
                    GOMove.FavL[k] = v
                end
            end
            GOMove:Update()
        end
    end
)
