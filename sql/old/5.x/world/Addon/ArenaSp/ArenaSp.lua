ArenaSp = LibStub("AceAddon-3.0"):NewAddon("ArenaSp", "AceEvent-3.0","AceConsole-3.0","AceTimer-3.0","AceHook-3.0")
local LN = LibStub("LibNameplate-1.0")
local addon,db,lunits,runits,casts

local defaults = {
global = {
lunits = {},
runits = {},
history = {},
casts = {},
},
profile = {
state = false,
cVars = {},
},
}


function ArenaSp:OnInitialize()
self.db = LibStub("AceDB-3.0"):New("ArenaSpDB", defaults, true)
db = self.db
addon = tostring(self)
lunits,runits,history,casts = db.global.lunits,db.global.runits,db.global.history,db.global.casts
wipe(lunits)
wipe(runits)
wipe(history)
wipe(casts)
--self:Print("ArenaSp initiated")
end



function ArenaSp:OnEnable()
--региструруем перехват ивентов
self:RegisterEvent("PLAYER_ENTERING_WORLD")
self:SaveCVars()
self:Print('ArenaSp by Darkey loaded. Current ArenaSp state is: '..tostring(db.profile.state))
end



function ArenaSp:UpdateCast(side,index,guid,spellId,type,time,casttime,spellExtra,spellExtra2)
local castStart,castEnd = time,time+casttime
local class, classFilename, race, raceFilename, sex, name, realm = GetPlayerInfoByGUID(guid)

local plate,platehealth,platehealthmax,isCasting = LN:GetNameplateByName(name),nil,nil,nil
if plate~=nil then
platehealth = LN:GetHealth(plate)
platehealthmax = LN:GetHealthMax(plate)
isCasting=LN:IsCasting(plate)
end

if db.global.casts[guid]==nil then db.global.casts[guid]=0 end

local cbBar = _G[addon..side..index.."cbbar"]
local cbIcon = _G[addon..side..index.."cbicon"]
local cbSpelltag = _G[addon..side..index.."cbspelltag"]

if type=="SPELL_CAST_START" then
if cbBar~=nil then
cbBar:SetScript("OnUpdate", function(self)
local timeSinceStart = GetTime()-castStart
local timeLeft = castEnd-GetTime()
local castTime = castEnd - castStart
local currentPercent = timeSinceStart / castTime * 100
if timeLeft>=0 then
cbBar:SetValue(currentPercent)
cbSpelltag.text:SetText(string.format("%.1f",timeLeft))
elseif timeLeft<=-0.5 or (isCasting~=nil and isCasting==false) then
cbBar:SetValue(0)
cbSpelltag.text:SetText("")
cbIcon.icon:SetTexture()
cbBar:SetScript("OnUpdate", nil)
end
end)
end

db.global.casts[guid]=spellId
local icon = select(3,GetSpellInfo(spellId))
if icon~=nil and cbIcon.icon:GetTexture()~=icon then cbIcon.icon:SetTexture(icon) end
end


if type=="SPELL_CAST_SUCCESS" and db.global.casts[guid]==spellId then
if cbBar~=nil then
cbBar:SetScript("OnUpdate", nil)
cbBar:SetValue(100)
cbSpelltag.text:SetText("SUCCESS")
cbBar:SetScript("OnUpdate", function(self)
local timeLeft = castEnd-GetTime()
if timeLeft<=-0.5 then
cbBar:SetValue(0)
cbSpelltag.text:SetText("")
cbIcon.icon:SetTexture()
cbBar:SetScript("OnUpdate", nil)
db.global.casts[guid]=0
end
end)
end
end


if type=="SPELL_CAST_FAILED" and db.global.casts[guid]==spellId then
if cbBar~=nil then
if spellExtra2~=SPELL_FAILED_SPELL_IN_PROGRESS then
cbBar:SetScript("OnUpdate", nil)
cbSpelltag.text:SetText("FAILED")
end
end
end

end


function ArenaSp:OnDisable()
--отменяем регистрацию перехвата ивентов
self:UnregisterAllEvents()
--self:Print("ArenaSp disabled")
end



function ArenaSp:CreateParent(side)
local frame = _G[addon..side]
if frame==nil then
local tab,point=58,"LEFT"; if side=="right" then tab,point=-58,"RIGHT" end
frame = CreateFrame("Frame",addon..side,WorldFrame)
frame:SetWidth(250)
frame:SetHeight(50)
frame:ClearAllPoints()
--frame:SetBackdrop({bgFile = "Interface\\Buttons\\WHITE8X8"})
frame:SetPoint(point, UIParent, point, tab, 0)
end
end


function ArenaSp:CreateUnit(side,index)
local frame = _G[addon..side]
if frame==nil then ArenaSp:CreateParent(side) end

local anchor,uarray,cpoint,ipoint
if side=="left" then anchor,uarray,hpoint,cpoint,ipoint="TOPLEFT",lunits,1,201,-48 else anchor,uarray,hpoint,cpoint,ipoint="TOPRIGHT",runits,-1,-201,48 end
local top=0; if index>1 then top=100*(index-1) end

local button = _G[addon..side..index.."button"]
if button==nil then
button = CreateFrame("Frame", addon..side..index.."button", _G[addon..side])
button:SetWidth(250)
button:SetHeight(50)
button:SetPoint(anchor, 0, -top)
button:SetBackdrop({bgFile="Interface\\DialogFrame\\UI-DialogBox-Background", edgeFile="Interface\\BUTTONS\\UI-ActionButton-Border", edgeSize=1});
end

local hpBar = _G[addon..side..index.."health"]
if hpBar==nil then
hpBar = CreateFrame("StatusBar", addon..side..index.."health", button)
hpBar:SetStatusBarTexture("Interface\\TargetingFrame\\UI-StatusBar")
hpBar:GetStatusBarTexture():SetHorizTile(false)
hpBar:SetMinMaxValues(0,1)
hpBar:SetValue(1)
hpBar:SetWidth(200)
hpBar:SetHeight(48)
hpBar:SetPoint(anchor,hpoint,-1)
end

local cIcon = _G[addon..side..index.."icon"]
if cIcon ==nil then
cIcon = CreateFrame("Frame", addon..side..index.."icon", button)
cIcon:SetWidth(48)
cIcon:SetHeight(48)
cIcon:ClearAllPoints()
cIcon:SetBackdrop({bgFile = "Interface\\DialogFrame\\UI-DialogBox-Background"})
cIcon:SetPoint(anchor, cpoint, -1)
cIcon.icon = cIcon:CreateTexture(nil,"CENTER")
cIcon.icon:SetAllPoints(cIcon)
end

local tIcon = _G[addon..side..index.."trinket"]
if tIcon==nil then
local tIcon = CreateFrame("Frame", addon..side..index.."trinket", button)
tIcon:SetWidth(48)
tIcon:SetHeight(48)
tIcon:ClearAllPoints()
tIcon:SetBackdrop({bgFile = "Interface\\DialogFrame\\UI-DialogBox-Background",nil})
tIcon:SetPoint(anchor, ipoint, -1)
tIcon:SetFrameStrata("BACKGROUND")
tIcon.icon = tIcon:CreateTexture(nil,"CENTER")
tIcon.icon:SetAllPoints(tIcon)
end

local tCD = _G[addon..side..index.."tcd"]
if tCD==nil then
tCD = CreateFrame("Cooldown", addon..side..index.."tcd", button)
tCD:SetWidth(48)
tCD:SetHeight(48)
tCD:ClearAllPoints()
tCD:SetBackdrop({bgFile = "Interface\\DialogFrame\\UI-DialogBox-Background",nil})
tCD:SetPoint(anchor, ipoint, -1)
tCD:SetFrameStrata("HIGH")
tCD.icon = tCD:CreateTexture(nil,"CENTER")
tCD.icon:SetAllPoints(tCD)
tCD.text = tCD:CreateFontString(addon..side..index.."tcdtext")
tCD.text:SetPoint("CENTER", 0, 0)
tCD.text:SetFont(STANDARD_TEXT_FONT, 16, "OUTLINE")
tCD.text:SetText("")
end

local nametag = _G[addon..side..index.."nametag"]
if nametag==nil then
nametag = CreateFrame("Button", addon..side..index.."nametag", hpBar)
nametag:SetHeight(48)
nametag:SetWidth(100)
nametag:SetPoint("LEFT", 5, 0)
nametag.text = nametag:CreateFontString(addon..side..index.."nametagtext")
nametag.text:SetPoint("LEFT", 0, 0)
nametag.text:SetFont(STANDARD_TEXT_FONT, 12, "OUTLINE")
nametag.text:SetText("")
end

local hptag = _G[addon..side..index.."hptag"]
if hptag==nil then
hptag = CreateFrame("Button", addon..side..index.."hptag", hpBar)
hptag:SetHeight(48)
hptag:SetWidth(100)
hptag:SetPoint("RIGHT", -5, 0)
hptag.text = hptag:CreateFontString(addon..side..index.."hptagtext")
hptag.text:SetPoint("RIGHT", 0, 0)
hptag.text:SetFont(STANDARD_TEXT_FONT, 12, "OUTLINE")
hptag.text:SetText("")
end


for i=1,3 do
local story = _G[addon..side..index.."story"..i]
if story==nil then
story = CreateFrame("Frame", addon..side..index.."story"..i, cIcon)
story:SetWidth(24)
story:SetHeight(24)
story:ClearAllPoints()
--story:SetBackdrop({bgFile = "Interface\\DialogFrame\\UI-DialogBox-Background"})
story:SetPoint(anchor, -(ipoint/2)-(ipoint*i/2), -25)
story.icon = story:CreateTexture(nil,"CENTER")
story.icon:SetAllPoints(story)
--[[
story.anim = story:CreateAnimationGroup()
story.anim.a1 = story.anim:CreateAnimation("Translation")
story.anim.a1:SetOffset(24, 0)    
story.anim.a1:SetDuration(1)
story.anim.a1:SetSmoothing("IN_OUT")
]]--
end
end


--castbar
local cbButton = _G[addon..side..index.."cbbutton"]
if cbButton==nil then
cbButton= CreateFrame("Frame", addon..side..index.."cbbutton", button)
cbButton:SetWidth(250)
cbButton:SetHeight(26)
cbButton:SetPoint("BOTTOMLEFT", 0, -26)
cbButton:SetBackdrop({bgFile="Interface\\DialogFrame\\UI-DialogBox-Background", edgeFile="Interface\\BUTTONS\\UI-ActionButton-Border", edgeSize=1});
end

local cbBar = _G[addon..side..index.."cbbar"]
if cbBar==nil then
cbBar = CreateFrame("StatusBar", addon..side..index.."cbbar", cbButton)
cbBar:SetStatusBarTexture("Interface\\TargetingFrame\\UI-StatusBar")
cbBar:GetStatusBarTexture():SetHorizTile(false)
cbBar:SetMinMaxValues(0,100)
cbBar:SetValue(0)
cbBar:SetWidth(248)
cbBar:SetHeight(24)
cbBar:SetPoint("TOPLEFT",1,-1)
end

local cbIcon = _G[addon..side..index.."cbicon"]
if cbIcon==nil then
cbIcon = CreateFrame("Frame", addon..side..index.."cbicon", cbButton)
cbIcon:SetWidth(24)
cbIcon:SetHeight(24)
cbIcon:ClearAllPoints()
--cbIcon:SetBackdrop({bgFile = "Interface\\DialogFrame\\UI-DialogBox-Background"})
cbIcon:SetPoint("LEFT", -24, 0)
cbIcon.icon = cbIcon:CreateTexture(nil,"CENTER")
cbIcon.icon:SetAllPoints(cbIcon)
end

local cbSpelltag = _G[addon..side..index.."cbspelltag"]
if cbSpelltag==nil then
cbSpelltag = CreateFrame("Button", addon..side..index.."cbspelltag", cbButton)
cbSpelltag:SetHeight(24)
cbSpelltag:SetWidth(248)
cbSpelltag:SetPoint("TOPRIGHT", -5, -1)
cbSpelltag.text = cbSpelltag:CreateFontString(addon..side..index.."cbspelltagtext")
cbSpelltag.text:SetPoint("RIGHT", 0, 0)
cbSpelltag.text:SetFont(STANDARD_TEXT_FONT, 12, "OUTLINE")
cbSpelltag.text:SetText("")
end

--castbar end

end


function ArenaSp:ResetAllUnits()
for i=1,5 do
self:ResetUnit("left",i)
self:ResetUnit("right",i)
end
end



function ArenaSp:ResetUnit(side,index)
self:FrameHide(addon..side)

local button = _G[addon..side..index.."button"]
if button~=nil then
self:FrameHide(button)
end

local hpBar = _G[addon..side..index.."health"]
if hpBar~=nil then
hpBar:SetMinMaxValues(0, 1)
hpBar:SetValue(1)
hpBar:SetStatusBarColor(211,211,211,0)
self:FrameHide(hpBar)
end

local cIcon = _G[addon..side..index.."icon"]
if cIcon~=nil then
cIcon.icon:SetTexture()
self:FrameHide(cIcon)
end

local tIcon = _G[addon..side..index.."trinket"]
if tIcon~=nil then
tIcon.icon:SetTexture()
self:FrameHide(tIcon)
end

local tCD = _G[addon..side..index.."tcd"]
if tCD~=nil then
tCD:SetCooldown(0,0)
tCD.icon:SetTexture()
tCD.text:SetText("")
self:FrameHide(tCD)
end


local nametag = _G[addon..side..index.."nametag"]
if nametag~=nil then
nametag.text:SetText("")
self:FrameHide(nametag)
end

local hptag = _G[addon..side..index.."hptag"]
if hptag~=nil then
hptag.text:SetText("")
self:FrameHide(hptag)
end


for i=1,3 do
local story = _G[addon..side..index.."story"..i]
if story~=nil then
story.icon:SetTexture()
self:FrameHide(story)
end
end

local cbButton = _G[addon..side..index.."cbbutton"] if cbButton~=nil then self:FrameHide(cbButton) end
local cbBar = _G[addon..side..index.."cbbar"] if cbBar~=nil then self:FrameHide(cbBar) end
local cbIcon = _G[addon..side..index.."cbicon"] if cbIcon~=nil then self:FrameHide(cbIcon) end
local cbSpelltag = _G[addon..side..index.."cbspelltag"] if cbSpelltag~=nil then self:FrameHide(cbSpelltag) end

end



function ArenaSp:UpdateUnit(side,index)
local uarray; if side=="left" then uarray=lunits else uarray=runits end
local guid = uarray[index]
local class, classFilename, race, raceFilename, sex, name, realm = GetPlayerInfoByGUID(guid)

local plate,platehealth,platehealthmax,isCasting = LN:GetNameplateByName(name),nil,nil,nil
if plate~=nil then
platehealth = LN:GetHealth(plate)
platehealthmax = LN:GetHealthMax(plate)
isCasting=LN:IsCasting(plate)
end

local button = _G[addon..side..index.."button"]
if button==nil then 
self:CreateUnit(side,index)
else

local hpBar = _G[addon..side..index.."health"]
if hpBar~=nil then
local color = self:GetHpBarColor(classFilename)
hpBar:SetStatusBarColor(color.r, color.g, color.b, color.a or 1)
if platehealth~=nil and platehealthmax~=nil then hpBar:SetMinMaxValues(0, platehealthmax) hpBar:SetValue(platehealth) end
self:FrameShow(hpBar)
end

local cIcon = _G[addon..side..index.."icon"]
if cIcon~=nil then
cIcon.icon:SetTexture("Interface\\GLUES\\CHARACTERCREATE\\UI-CHARACTERCREATE-CLASSES")
local coords = CLASS_ICON_TCOORDS[classFilename]
cIcon.icon:SetTexCoord(unpack(coords))
self:FrameShow(cIcon)
end

local tIcon = _G[addon..side..index.."trinket"]
if tIcon~=nil then
tIcon.icon:SetTexture("Interface\\Icons\\inv_jewelry_trinketpvp_01")
self:FrameShow(tIcon)
end

local tCD = _G[addon..side..index.."tcd"]
if tCD~=nil then
if tCD.icon:GetTexture()==nil then tCD.icon:SetTexture("Interface\\Icons\\inv_jewelry_trinketpvp_01") end
local duration = tCD:GetCooldownDuration()
if duration~=0 then
local cd = tCD:GetAttribute("timeused")
if cd~=nil then
local remain = 120-(GetTime()-cd)
if (remain >= 60) then
tCD.text:SetText(ceil(remain/60).."m");
else
tCD.text:SetText(ceil(remain));
end
end
end
self:FrameShow(tCD)
end

local nametag = _G[addon..side..index.."nametag"]
if nametag~=nil then
nametag.text:SetText(name)
self:FrameShow(nametag)
end

local hptag = _G[addon..side..index.."hptag"]
if hptag~=nil then
if platehealth~=nil and platehealthmax~=nil then
if platehealth > 999 then platehealth=string.format("%.1fk", (platehealth / 1000)) end
if platehealthmax > 999 then platehealthmax=string.format("%.1fk", (platehealthmax / 1000)) end
hptag.text:SetText(platehealth.."/"..platehealthmax)
end
self:FrameShow(hptag)
end


for i=1,3 do
local story = _G[addon..side..index.."story"..i]
if story~=nil then
if history[guid]~=nil and history[guid][i]~=nil then
local icon = select(3,GetSpellInfo(history[guid][i]))
if icon~=nil and story.icon:GetTexture()~=icon then story.icon:SetTexture(icon) end
story:SetScript("OnEnter", function(self)
GameTooltip:SetOwner(self, "ANCHOR_RIGHT")
GameTooltip:SetParent(WorldFrame)
GameTooltip:SetSpellByID(history[guid][i])
end)
story:SetScript("OnLeave", function(self) GameTooltip:Hide() end)
end
self:FrameShow(story)
end
end


local cbButton = _G[addon..side..index.."cbbutton"] if cbButton~=nil then self:FrameShow(cbButton) end
local cbBar = _G[addon..side..index.."cbbar"] if cbBar~=nil then self:FrameShow(cbBar) end
local cbIcon = _G[addon..side..index.."cbicon"] if cbIcon~=nil then self:FrameShow(cbIcon) end
local cbSpelltag = _G[addon..side..index.."cbspelltag"] if cbSpelltag~=nil then self:FrameShow(cbSpelltag) end

self:FrameShow(button)
self:FrameShow(addon..side)
end
end


function ArenaSp:UpdateUnitGUID(eventName, ...)
if db.profile.state==true then

local timestamp, type, hideCaster, sourceGUID, sourceName, sourceFlags, sourceFlags2, destGUID, destName, destFlags, destFlags2, spellId, spellName, spellExtra, spellExtra2 = select(1, ...)

if sourceGUID~=nil and destGUID~=nil and sourceGUID~=UnitGUID("player") and destGUID~=UnitGUID("player") and self:ParseGUID(sourceGUID) and self:ParseGUID(destGUID) then
if sourceName~=nil and destName~=nil and sourceName~=destName and spellId~=nil then

local harm = {'SPELL_DAMAGE','SPELL_PERIODIC_DAMAGE','SWING_DAMAGE','RANGE_DAMAGE','SPELL_MISSED','SPELL_PERIODIC_MISSED','SWING_MISSED','RANGE_MISSED'}
local help = {'SPELL_HEAL','SPELL_PERIODIC_HEAL','SPELL_ENERGIZE'}

local insert=0
if tContains(harm,type) then

if insert==0 and tContains(lunits,sourceGUID)~=1 and tContains(runits,sourceGUID)~=1 then
if #lunits==0 and #runits==0 then
tinsert(lunits,sourceGUID)
insert=1
end
end

if insert==0 and tContains(lunits,sourceGUID)==1 and tContains(lunits,destGUID)~=1 and tContains(runits,destGUID)~=1 then
tinsert(runits,destGUID)
insert=1
end

if insert==0 and tContains(runits,sourceGUID)==1 and tContains(lunits,destGUID)~=1 and tContains(runits,destGUID)~=1 then
tinsert(lunits,destGUID)
insert=1
end

if insert==0 and tContains(lunits,sourceGUID)~=1 and tContains(runits,sourceGUID)~=1 and tContains(lunits,destGUID)~=1 and tContains(runits,destGUID)==1 then
tinsert(lunits,sourceGUID)
insert=1
end

if insert==0 and tContains(lunits,sourceGUID)~=1 and tContains(runits,sourceGUID)~=1 and tContains(lunits,destGUID)==1 and tContains(runits,destGUID)~=1 then
tinsert(runits,sourceGUID)
insert=1
end

elseif tContains(help,type) then

if insert==0 and tContains(lunits,sourceGUID)~=1 and tContains(runits,sourceGUID)~=1 and tContains(lunits,destGUID)~=1 and tContains(runits,destGUID)~=1 then
if #lunits==0 and #runits==0 then
tinsert(lunits,sourceGUID)
tinsert(lunits,destGUID)
insert=1
end
end

if insert==0 and tContains(lunits,sourceGUID)~=1 and tContains(runits,sourceGUID)~=1 and tContains(lunits,destGUID)==1 then
tinsert(lunits,sourceGUID)
insert=1
end

if insert==0 and tContains(lunits,sourceGUID)~=1 and tContains(runits,sourceGUID)~=1 and tContains(runits,destGUID)==1 then
tinsert(runits,sourceGUID)
insert=1
end

else
--print(sourceName,({GetSpellLink(spellId)})[1],destName,type)
end

end

if type=="SPELL_CAST_SUCCESS" then
if history[sourceGUID]==nil then history[sourceGUID] = {}
else
tinsert(history[sourceGUID],1,spellId)
if history[sourceGUID][4]~=nil then history[sourceGUID][4]=nil end
end
end


end


local lframe = _G[addon.."left"]
if lframe~=nil and lframe:GetHeight()~=#lunits*100 then lframe:SetHeight(#lunits*100) end
for i=1,#lunits do self:UpdateUnit("left",i) end

local rframe = _G[addon.."right"]
if rframe~=nil and rframe:GetHeight()~=#runits*100 then rframe:SetHeight(#runits*100) end
for i=1,#runits do self:UpdateUnit("right",i) end


if sourceGUID~=nil and sourceGUID~=UnitGUID("player") and self:ParseGUID(sourceGUID) then
local casts = {"SPELL_CAST_START","SPELL_CAST_SUCCESS","SPELL_CAST_FAILED"}
if tContains(casts,type) and spellId~=nil then
if select(7,GetSpellInfo(spellId))/1000>0 then

local findex,fside = self:UnitPosition(lunits,sourceGUID),"right"
if findex==nil then findex=self:UnitPosition(runits,sourceGUID) else fside="left" end
if findex~=nil then
self:UpdateCast(fside,findex,sourceGUID,spellId,type,GetTime(),select(7,GetSpellInfo(spellId))/1000,spellExtra,spellExtra2)
end
end

end
end



if sourceGUID~=nil and sourceGUID~=UnitGUID("player") and self:ParseGUID(sourceGUID) and type=="SPELL_CAST_SUCCESS" and spellId~=nil then
local trinkets = {42292,59752}
if tContains(trinkets, spellId) then
local findex,fside = self:UnitPosition(lunits,sourceGUID),"right"
if findex==nil then findex=self:UnitPosition(runits,sourceGUID) else fside="left" end
if findex~=nil then
local tCD = _G[addon..fside..findex.."tcd"]
if tCD~=nil then
tCD:SetCooldown(GetTime(), 120)
tCD:SetAttribute("timeused", GetTime())
end
end
end
end



end
end


function ArenaSp:PLAYER_ENTERING_WORLD()
wipe(lunits)
wipe(runits)
wipe(history)
wipe(casts)
self:ResetAllUnits()
CombatLogClearEntries()

	-- проверяем на арене ли мы и есть ли на ней враги или члены группы
local instanceType = select(2, IsInInstance())
local acount=0; for i=1,5 do if UnitExists("arena"..i) or UnitExists("party"..i) then acount=acount+1 end end

if instanceType == "arena" and acount==0 then
self:SaveCVars()

SetCVar("ffxDeath","0")
SetCVar("nameplateShowEnemies","1")
SetCVar("nameplateShowEnemyGuardians","0")
SetCVar("nameplateShowEnemyPets","0")
SetCVar("nameplateShowEnemyTotems","0")
SetCVar("showVKeyCastbar","1")

local toggleui = _G[addon.."toggleui"]
if toggleui==nil then
toggleui = CreateFrame("Button", addon.."toggleui", WorldFrame)
toggleui:SetHeight(30)
toggleui:SetWidth(120)
toggleui:SetPoint("TOPLEFT", 10, -10)
toggleui:SetBackdrop({bgFile="Interface\\DialogFrame\\UI-DialogBox-Background", edgeFile="Interface\\Buttons\\WHITE8X8", edgeSize=1});
toggleui:SetScript("OnClick", function() if UIParent:IsVisible()==1 then UIParent:Hide() else UIParent:Show() end end)
toggleui.text = toggleui:CreateFontString()
toggleui.text:SetFont(STANDARD_TEXT_FONT, 14, "OUTLINE")
toggleui.text:SetPoint("CENTER", 0, 0)
toggleui.text:SetText("Toggle UI")
end

local leavearena = _G[addon.."leavearena"]
if leavearena==nil then 
local leavearena = CreateFrame("Button", addon.."leavearena", WorldFrame)
leavearena:SetHeight(30)
leavearena:SetWidth(120)
leavearena:SetPoint("TOPLEFT", 140, -10)
leavearena:SetBackdrop({bgFile="Interface\\DialogFrame\\UI-DialogBox-Background", edgeFile="Interface\\Buttons\\WHITE8X8", edgeSize=1});
leavearena:SetScript("OnClick", function() if db.profile.state==true then SendChatMessage(".leavespectate","GUILD") end end)
leavearena.text = leavearena:CreateFontString()
leavearena.text:SetFont(STANDARD_TEXT_FONT, 14, "OUTLINE")
leavearena.text:SetPoint("CENTER", 0, 0)
leavearena.text:SetText("Leave arena")
end

UIParent:Hide()
self:FrameShow(addon.."toggleui")
self:FrameShow(addon.."leavearena")
db.profile.state=true
self:RegisterEvent("COMBAT_LOG_EVENT_UNFILTERED", "UpdateUnitGUID")
else
self:UnregisterEvent("COMBAT_LOG_EVENT_UNFILTERED")
db.profile.state=false
self:LoadCVars()
self:FrameHide(addon.."leavearena")
self:FrameHide(addon.."toggleui")
UIParent:Show()
end
end



function ArenaSp:ParseGUID(guid)
local unitType = FxFFF
local first3 = tonumber(strsub(guid, 1,5))
if first3~=nil then unitType = bit.band(first3,0x00F) end
if (unitType == 000) then return true else return false end
end


function ArenaSp:GetHpBarColor(class)
	return (RAID_CLASS_COLORS[class]) or { r = 0, g = 1, b = 0 }
end


function ArenaSp:GetMpBarColor(powerType)
return PowerBarColor[powerType]
end


function ArenaSp:FrameShow(fname)
local frame = fname
if type(fname)~="table" then frame=_G[fname] end
if frame~=nil and frame:GetAlpha()~=1 then frame:SetAlpha(1) end
if frame~=nil and frame:IsVisible()~=1 then frame:Show() end
end


function ArenaSp:FrameHide(fname)
local frame = fname
if type(fname)~="table" then frame=_G[fname] end
if frame~=nil and frame:GetAlpha()~=0 then frame:SetAlpha(0) end
if frame~=nil and frame:IsVisible()==1 then frame:Hide() end
end


function ArenaSp:SaveCVars()
db.profile.cVars.ffxDeath = GetCVar("ffxDeath")
db.profile.cVars.nameplateShowEnemies = GetCVar("nameplateShowEnemies")
db.profile.cVars.nameplateShowEnemyGuardians = GetCVar("nameplateShowEnemyGuardians")
db.profile.cVars.nameplateShowEnemyPets = GetCVar("nameplateShowEnemyPets")
db.profile.cVars.nameplateShowEnemyTotems = GetCVar("nameplateShowEnemyTotems")
db.profile.cVars.showVKeyCastbar = GetCVar("showVKeyCastbar")
end


function ArenaSp:LoadCVars()
if db.profile.cVars.ffxDeath~=nil then SetCVar("ffxDeath", db.profile.cVars.ffxDeath) end
if db.profile.cVars.nameplateShowEnemies~=nil then SetCVar("nameplateShowEnemies", db.profile.cVars.nameplateShowEnemies) end
if db.profile.cVars.nameplateShowEnemyGuardians~=nil then SetCVar("nameplateShowEnemyGuardians", db.profile.cVars.nameplateShowEnemyGuardians) end
if db.profile.cVars.nameplateShowEnemyPets~=nil then SetCVar("nameplateShowEnemyPets", db.profile.cVars.nameplateShowEnemyPets) end
if db.profile.cVars.nameplateShowEnemyPets~=nil then SetCVar("nameplateShowEnemyTotems", db.profile.cVars.nameplateShowEnemyTotems) end
if db.profile.cVars.showVKeyCastbar~=nil then SetCVar("showVKeyCastbar", db.profile.cVars.showVKeyCastbar) end
end

function ArenaSp:UnitPosition(table,guid)
local found=0
for i=1,#table do
if table[i]==guid then found=i break end
end
if found~=0 then return found else return nil end
end