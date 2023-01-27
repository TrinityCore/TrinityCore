--- AceDBOptions-3.0 provides a universal AceConfig options screen for managing AceDB-3.0 profiles.
-- @class file
-- @name AceDBOptions-3.0
-- @release $Id: AceDBOptions-3.0.lua 1066 2012-09-18 14:36:49Z nevcairiel $
local ACEDBO_MAJOR, ACEDBO_MINOR = "AceDBOptions-3.0", 14
local AceDBOptions, oldminor = LibStub:NewLibrary(ACEDBO_MAJOR, ACEDBO_MINOR)

if not AceDBOptions then return end -- No upgrade needed

-- Lua APIs
local pairs, next = pairs, next

-- WoW APIs
local UnitClass = UnitClass

-- Global vars/functions that we don't upvalue since they might get hooked, or upgraded
-- List them here for Mikk's FindGlobals script
-- GLOBALS: NORMAL_FONT_COLOR_CODE, FONT_COLOR_CODE_CLOSE

AceDBOptions.optionTables = AceDBOptions.optionTables or {}
AceDBOptions.handlers = AceDBOptions.handlers or {}

--[[
	Localization of AceDBOptions-3.0
]]

local L = {
	choose = "Existing Profiles",
	choose_desc = "You can either create a new profile by entering a name in the editbox, or choose one of the already existing profiles.",
	choose_sub = "Select one of your currently available profiles.",
	copy = "Copy From",
	copy_desc = "Copy the settings from one existing profile into the currently active profile.",
	current = "Current Profile:",
	default = "Default",
	delete = "Delete a Profile",
	delete_confirm = "Are you sure you want to delete the selected profile?",
	delete_desc = "Delete existing and unused profiles from the database to save space, and cleanup the SavedVariables file.",
	delete_sub = "Deletes a profile from the database.",
	intro = "You can change the active database profile, so you can have different settings for every character.",
	new = "New",
	new_sub = "Create a new empty profile.",
	profiles = "Profiles",
	profiles_sub = "Manage Profiles",
	reset = "Reset Profile",
	reset_desc = "Reset the current profile back to its default values, in case your configuration is broken, or you simply want to start over.",
	reset_sub = "Reset the current profile to the default",
}

local LOCALE = GetLocale()
if LOCALE == "deDE" then
	L["choose"] = "Vorhandene Profile"
	L["choose_desc"] = "Du kannst ein neues Profil erstellen, indem du einen neuen Namen in der Eingabebox 'Neu' eingibst, oder wähle eines der vorhandenen Profile aus."
	L["choose_sub"] = "Wählt ein bereits vorhandenes Profil aus."
	L["copy"] = "Kopieren von..."
	L["copy_desc"] = "Kopiere die Einstellungen von einem vorhandenen Profil in das aktive Profil."
	-- L["current"] = "Current Profile:"
	L["default"] = "Standard"
	L["delete"] = "Profil löschen"
	L["delete_confirm"] = "Willst du das ausgewählte Profil wirklich löschen?"
	L["delete_desc"] = "Lösche vorhandene oder unbenutzte Profile aus der Datenbank um Platz zu sparen und um die SavedVariables Datei 'sauber' zu halten."
	L["delete_sub"] = "Löscht ein Profil aus der Datenbank."
	L["intro"] = "Hier kannst du das aktive Datenbankprofile ändern, damit du verschiedene Einstellungen für jeden Charakter erstellen kannst, wodurch eine sehr flexible Konfiguration möglich wird."
	L["new"] = "Neu"
	L["new_sub"] = "Ein neues Profil erstellen."
	L["profiles"] = "Profile"
	L["profiles_sub"] = "Profile verwalten"
	L["reset"] = "Profil zurücksetzen"
	L["reset_desc"] = "Setzt das momentane Profil auf Standardwerte zurück, für den Fall das mit der Konfiguration etwas schief lief oder weil du einfach neu starten willst."
	L["reset_sub"] = "Das aktuelle Profil auf Standard zurücksetzen."
elseif LOCALE == "frFR" then
	L["choose"] = "Profils existants"
	L["choose_desc"] = "Vous pouvez créer un nouveau profil en entrant un nouveau nom dans la boîte de saisie, ou en choississant un des profils déjà existants."
	L["choose_sub"] = "Permet de choisir un des profils déjà disponibles."
	L["copy"] = "Copier à partir de"
	L["copy_desc"] = "Copie les paramètres d'un profil déjà existant dans le profil actuellement actif."
	-- L["current"] = "Current Profile:"
	L["default"] = "Défaut"
	L["delete"] = "Supprimer un profil"
	L["delete_confirm"] = "Etes-vous sûr de vouloir supprimer le profil sélectionné ?"
	L["delete_desc"] = "Supprime les profils existants inutilisés de la base de données afin de gagner de la place et de nettoyer le fichier SavedVariables."
	L["delete_sub"] = "Supprime un profil de la base de données."
	L["intro"] = "Vous pouvez changer le profil actuel afin d'avoir des paramètres différents pour chaque personnage, permettant ainsi d'avoir une configuration très flexible."
	L["new"] = "Nouveau"
	L["new_sub"] = "Créée un nouveau profil vierge."
	L["profiles"] = "Profils"
	L["profiles_sub"] = "Gestion des profils"
	L["reset"] = "Réinitialiser le profil"
	L["reset_desc"] = "Réinitialise le profil actuel au cas où votre configuration est corrompue ou si vous voulez tout simplement faire table rase."
	L["reset_sub"] = "Réinitialise le profil actuel avec les paramètres par défaut."
elseif LOCALE == "koKR" then
	L["choose"] = "프로필 선택"
	L["choose_desc"] = "새로운 이름을 입력하거나, 이미 있는 프로필중 하나를 선택하여 새로운 프로필을 만들 수 있습니다."
	L["choose_sub"] = "당신이 현재 이용할수 있는 프로필을 선택합니다."
	L["copy"] = "복사"
	L["copy_desc"] = "현재 사용중인 프로필에, 선택한 프로필의 설정을 복사합니다."
	-- L["current"] = "Current Profile:"
	L["default"] = "기본값"
	L["delete"] = "프로필 삭제"
	L["delete_confirm"] = "정말로 선택한 프로필의 삭제를 원하십니까?"
	L["delete_desc"] = "데이터베이스에 사용중이거나 저장된 프로파일 삭제로 SavedVariables 파일의 정리와 공간 절약이 됩니다."
	L["delete_sub"] = "데이터베이스의 프로필을 삭제합니다."
	L["intro"] = "모든 캐릭터의 다양한 설정과 사용중인 데이터베이스 프로필, 어느것이던지 매우 다루기 쉽게 바꿀수 있습니다."
	L["new"] = "새로운 프로필"
	L["new_sub"] = "새로운 프로필을 만듭니다."
	L["profiles"] = "프로필"
	L["profiles_sub"] = "프로필 설정"
	L["reset"] = "프로필 초기화"
	L["reset_desc"] = "단순히 다시 새롭게 구성을 원하는 경우, 현재 프로필을 기본값으로 초기화 합니다."
	L["reset_sub"] = "현재의 프로필을 기본값으로 초기화 합니다"
elseif LOCALE == "esES" or LOCALE == "esMX" then
	L["choose"] = "Perfiles existentes"
	L["choose_desc"] = "Puedes crear un nuevo perfil introduciendo un nombre en el recuadro o puedes seleccionar un perfil de los ya existentes."
	L["choose_sub"] = "Selecciona uno de los perfiles disponibles."
	L["copy"] = "Copiar de"
	L["copy_desc"] = "Copia los ajustes de un perfil existente al perfil actual."
	-- L["current"] = "Current Profile:"
	L["default"] = "Por defecto"
	L["delete"] = "Borrar un Perfil"
	L["delete_confirm"] = "¿Estas seguro que quieres borrar el perfil seleccionado?"
	L["delete_desc"] = "Borra los perfiles existentes y sin uso de la base de datos para ganar espacio y limpiar el archivo SavedVariables."
	L["delete_sub"] = "Borra un perfil de la base de datos."
	L["intro"] = "Puedes cambiar el perfil activo de tal manera que cada personaje tenga diferentes configuraciones."
	L["new"] = "Nuevo"
	L["new_sub"] = "Crear un nuevo perfil vacio."
	L["profiles"] = "Perfiles"
	L["profiles_sub"] = "Manejar Perfiles"
	L["reset"] = "Reiniciar Perfil"
	L["reset_desc"] = "Reinicia el perfil actual a los valores por defectos, en caso de que se haya estropeado la configuración o quieras volver a empezar de nuevo."
	L["reset_sub"] = "Reinicar el perfil actual al de por defecto"
elseif LOCALE == "zhTW" then
	L["choose"] = "現有的設定檔"
	L["choose_desc"] = "你可以通過在文本框內輸入一個名字創立一個新的設定檔，也可以選擇一個已經存在的設定檔。"
	L["choose_sub"] = "從當前可用的設定檔裏面選擇一個。"
	L["copy"] = "複製自"
	L["copy_desc"] = "從當前某個已保存的設定檔複製到當前正使用的設定檔。"
	-- L["current"] = "Current Profile:"
	L["default"] = "預設"
	L["delete"] = "刪除一個設定檔"
	L["delete_confirm"] = "你確定要刪除所選擇的設定檔嗎？"
	L["delete_desc"] = "從資料庫裏刪除不再使用的設定檔，以節省空間，並且清理SavedVariables檔。"
	L["delete_sub"] = "從資料庫裏刪除一個設定檔。"
	L["intro"] = "你可以選擇一個活動的資料設定檔，這樣你的每個角色就可以擁有不同的設定值，可以給你的插件設定帶來極大的靈活性。"
	L["new"] = "新建"
	L["new_sub"] = "新建一個空的設定檔。"
	L["profiles"] = "設定檔"
	L["profiles_sub"] = "管理設定檔"
	L["reset"] = "重置設定檔"
	L["reset_desc"] = "將當前的設定檔恢復到它的預設值，用於你的設定檔損壞，或者你只是想重來的情況。"
	L["reset_sub"] = "將當前的設定檔恢復為預設值"
elseif LOCALE == "zhCN" then
	L["choose"] = "现有的配置文件"
	L["choose_desc"] = "你可以通过在文本框内输入一个名字创立一个新的配置文件，也可以选择一个已经存在的配置文件。"
	L["choose_sub"] = "从当前可用的配置文件里面选择一个。"
	L["copy"] = "复制自"
	L["copy_desc"] = "从当前某个已保存的配置文件复制到当前正使用的配置文件。"
	-- L["current"] = "Current Profile:"
	L["default"] = "默认"
	L["delete"] = "删除一个配置文件"
	L["delete_confirm"] = "你确定要删除所选择的配置文件么？"
	L["delete_desc"] = "从数据库里删除不再使用的配置文件，以节省空间，并且清理SavedVariables文件。"
	L["delete_sub"] = "从数据库里删除一个配置文件。"
	L["intro"] = "你可以选择一个活动的数据配置文件，这样你的每个角色就可以拥有不同的设置值，可以给你的插件配置带来极大的灵活性。"
	L["new"] = "新建"
	L["new_sub"] = "新建一个空的配置文件。"
	L["profiles"] = "配置文件"
	L["profiles_sub"] = "管理配置文件"
	L["reset"] = "重置配置文件"
	L["reset_desc"] = "将当前的配置文件恢复到它的默认值，用于你的配置文件损坏，或者你只是想重来的情况。"
	L["reset_sub"] = "将当前的配置文件恢复为默认值"
elseif LOCALE == "ruRU" then
	L["choose"] = "Существующие профили"
	L["choose_desc"] = "Вы можете создать новый профиль, введя название в поле ввода, или выбрать один из уже существующих профилей."
	L["choose_sub"] = "Выбор одиного из уже доступных профилей"
	L["copy"] = "Скопировать из"
	L["copy_desc"] = "Скопировать настройки из выбранного профиля в активный."
	-- L["current"] = "Current Profile:"
	L["default"] = "По умолчанию"
	L["delete"] = "Удалить профиль"
	L["delete_confirm"] = "Вы уверены, что вы хотите удалить выбранный профиль?"
	L["delete_desc"] = "Удалить существующий и неиспользуемый профиль из БД для сохранения места, и очистить SavedVariables файл."
	L["delete_sub"] = "Удаление профиля из БД"
	L["intro"] = "Изменяя активный профиль, вы можете задать различные настройки модификаций для каждого персонажа."
	L["new"] = "Новый"
	L["new_sub"] = "Создать новый чистый профиль"
	L["profiles"] = "Профили"
	L["profiles_sub"] = "Управление профилями"
	L["reset"] = "Сброс профиля"
	L["reset_desc"] = "Если ваша конфигурации испорчена или если вы хотите настроить всё заново - сбросьте текущий профиль на стандартные значения."
	L["reset_sub"] = "Сброс текущего профиля на стандартный"
elseif LOCALE == "itIT" then
	L["choose"] = "Profili esistenti"
	L["choose_desc"] = "Puoi creare un nuovo profilo digitando il nome della casella di testo, oppure scegliendone uno tra i profili gia' esistenti."
	L["choose_sub"] = "Seleziona uno dei profili disponibili."
	L["copy"] = "Copia Da"
	L["copy_desc"] = "Copia le impostazioni da un profilo esistente, nel profilo attivo in questo momento."
	L["current"] = "Profilo Attivo:"
	L["default"] = "Standard"
	L["delete"] = "Cancella un profilo"
	L["delete_confirm"] = "Sei sicuro di voler cancellare il profilo selezionato?"
	L["delete_desc"] = "Cancella i profili non utilizzati dal database per risparmiare spazio e mantenere puliti i file di configurazione SavedVariables."
	L["delete_sub"] = "Cancella un profilo dal Database."
	L["intro"] = "Puoi cambiare il profilo attivo, in modo da usare impostazioni diverse per ogni personaggio."
	L["new"] = "Nuovo"
	L["new_sub"] = "Crea un nuovo profilo vuoto."
	L["profiles"] = "Profili"
	L["profiles_sub"] = "Gestisci Profili"
	L["reset"] = "Reimposta Profilo"
	L["reset_desc"] = "Riporta il tuo profilo attivo alle sue impostazioni di default, nel caso in cui la tua configurazione si sia corrotta, o semplicemente tu voglia re-inizializzarla."
	L["reset_sub"] = "Reimposta il profilo ai suoi valori di default."
end

local defaultProfiles
local tmpprofiles = {}

-- Get a list of available profiles for the specified database.
-- You can specify which profiles to include/exclude in the list using the two boolean parameters listed below.
-- @param db The db object to retrieve the profiles from
-- @param common If true, getProfileList will add the default profiles to the return list, even if they have not been created yet
-- @param nocurrent If true, then getProfileList will not display the current profile in the list
-- @return Hashtable of all profiles with the internal name as keys and the display name as value.
local function getProfileList(db, common, nocurrent)
	local profiles = {}
	
	-- copy existing profiles into the table
	local currentProfile = db:GetCurrentProfile()
	for i,v in pairs(db:GetProfiles(tmpprofiles)) do 
		if not (nocurrent and v == currentProfile) then 
			profiles[v] = v 
		end 
	end
	
	-- add our default profiles to choose from ( or rename existing profiles)
	for k,v in pairs(defaultProfiles) do
		if (common or profiles[k]) and not (nocurrent and k == currentProfile) then
			profiles[k] = v
		end
	end
	
	return profiles
end

--[[
	OptionsHandlerPrototype
	prototype class for handling the options in a sane way
]]
local OptionsHandlerPrototype = {}

--[[ Reset the profile ]]
function OptionsHandlerPrototype:Reset()
	self.db:ResetProfile()
end

--[[ Set the profile to value ]]
function OptionsHandlerPrototype:SetProfile(info, value)
	self.db:SetProfile(value)
end

--[[ returns the currently active profile ]]
function OptionsHandlerPrototype:GetCurrentProfile()
	return self.db:GetCurrentProfile()
end

--[[ 
	List all active profiles
	you can control the output with the .arg variable
	currently four modes are supported
	
	(empty) - return all available profiles
	"nocurrent" - returns all available profiles except the currently active profile
	"common" - returns all avaialble profiles + some commonly used profiles ("char - realm", "realm", "class", "Default")
	"both" - common except the active profile
]]
function OptionsHandlerPrototype:ListProfiles(info)
	local arg = info.arg
	local profiles
	if arg == "common" and not self.noDefaultProfiles then
		profiles = getProfileList(self.db, true, nil)
	elseif arg == "nocurrent" then
		profiles = getProfileList(self.db, nil, true)
	elseif arg == "both" then -- currently not used
		profiles = getProfileList(self.db, (not self.noDefaultProfiles) and true, true)
	else
		profiles = getProfileList(self.db)
	end
	
	return profiles
end

function OptionsHandlerPrototype:HasNoProfiles(info)
	local profiles = self:ListProfiles(info)
	return ((not next(profiles)) and true or false)
end

--[[ Copy a profile ]]
function OptionsHandlerPrototype:CopyProfile(info, value)
	self.db:CopyProfile(value)
end

--[[ Delete a profile from the db ]]
function OptionsHandlerPrototype:DeleteProfile(info, value)
	self.db:DeleteProfile(value)
end

--[[ fill defaultProfiles with some generic values ]]
local function generateDefaultProfiles(db)
	defaultProfiles = {
		["Default"] = L["default"],
		[db.keys.char] = db.keys.char,
		[db.keys.realm] = db.keys.realm,
		[db.keys.class] = UnitClass("player")
	}
end

--[[ create and return a handler object for the db, or upgrade it if it already existed ]]
local function getOptionsHandler(db, noDefaultProfiles)
	if not defaultProfiles then
		generateDefaultProfiles(db)
	end
	
	local handler = AceDBOptions.handlers[db] or { db = db, noDefaultProfiles = noDefaultProfiles }
	
	for k,v in pairs(OptionsHandlerPrototype) do
		handler[k] = v
	end
	
	AceDBOptions.handlers[db] = handler
	return handler
end

--[[
	the real options table 
]]
local optionsTable = {
	desc = {
		order = 1,
		type = "description",
		name = L["intro"] .. "\n",
	},
	descreset = {
		order = 9,
		type = "description",
		name = L["reset_desc"],
	},
	reset = {
		order = 10,
		type = "execute",
		name = L["reset"],
		desc = L["reset_sub"],
		func = "Reset",
	},
	current = {
		order = 11,
		type = "description",
		name = function(info) return L["current"] .. " " .. NORMAL_FONT_COLOR_CODE .. info.handler:GetCurrentProfile() .. FONT_COLOR_CODE_CLOSE end,
		width = "default",
	},
	choosedesc = {
		order = 20,
		type = "description",
		name = "\n" .. L["choose_desc"],
	},
	new = {
		name = L["new"],
		desc = L["new_sub"],
		type = "input",
		order = 30,
		get = false,
		set = "SetProfile",
	},
	choose = {
		name = L["choose"],
		desc = L["choose_sub"],
		type = "select",
		order = 40,
		get = "GetCurrentProfile",
		set = "SetProfile",
		values = "ListProfiles",
		arg = "common",
	},
	copydesc = {
		order = 50,
		type = "description",
		name = "\n" .. L["copy_desc"],
	},
	copyfrom = {
		order = 60,
		type = "select",
		name = L["copy"],
		desc = L["copy_desc"],
		get = false,
		set = "CopyProfile",
		values = "ListProfiles",
		disabled = "HasNoProfiles",
		arg = "nocurrent",
	},
	deldesc = {
		order = 70,
		type = "description",
		name = "\n" .. L["delete_desc"],
	},
	delete = {
		order = 80,
		type = "select",
		name = L["delete"],
		desc = L["delete_sub"],
		get = false,
		set = "DeleteProfile",
		values = "ListProfiles",
		disabled = "HasNoProfiles",
		arg = "nocurrent",
		confirm = true,
		confirmText = L["delete_confirm"],
	},
}

--- Get/Create a option table that you can use in your addon to control the profiles of AceDB-3.0.
-- @param db The database object to create the options table for.
-- @return The options table to be used in AceConfig-3.0
-- @usage 
-- -- Assuming `options` is your top-level options table and `self.db` is your database:
-- options.args.profiles = LibStub("AceDBOptions-3.0"):GetOptionsTable(self.db)
function AceDBOptions:GetOptionsTable(db, noDefaultProfiles)
	local tbl = AceDBOptions.optionTables[db] or {
			type = "group",
			name = L["profiles"],
			desc = L["profiles_sub"],
		}
	
	tbl.handler = getOptionsHandler(db, noDefaultProfiles)
	tbl.args = optionsTable

	AceDBOptions.optionTables[db] = tbl
	return tbl
end

-- upgrade existing tables
for db,tbl in pairs(AceDBOptions.optionTables) do
	tbl.handler = getOptionsHandler(db)
	tbl.args = optionsTable
end
