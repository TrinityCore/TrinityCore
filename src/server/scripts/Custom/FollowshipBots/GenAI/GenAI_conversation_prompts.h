/*
 * This file is part of the Stefal WoW Project.
 * It is designed to work exclusively with the TrinityCore framework.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * This code is provided for personal and educational use within the
 * Stefal WoW Project. It is not intended for commercial distribution,
 * resale, or any form of monetization.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "Define.h"

#include <atomic>
#include <memory>
#include <mutex>
#include <string>
#include <utility>
#include <vector>
#include <unordered_map>

class Creature;

namespace FSBChat { struct ActiveConversation; }

namespace FSBConvPrompts
{
    enum class ConversationTopicCategory
    {
        Joke,
        Complaint,
        ZoneEvent,
        RandomTake,
        Political,
        Question,
        Story,
        TimeOfDay,
        Weather
    };

    enum class ConversationTopicSubCategory
    {
        ZoneJoke,
        NPCJoke,
        BossJoke,
        ProfessionJoke,
        ClassJoke,
        ZoneComplaint,
        NPCComplaint,
        ClassComplaint,
        ZoneEvent,
        NPCEvent,
        FactionOpinion,
        RaceOpinion,
        ClassOpinion,
        ThematicQuestion,
        AdventureStory,
        BossEncounterStory,
        TimeOfDayComment,
        WeatherComment
    };

    enum class TopicDataSource : uint8
    {
        ZoneFeature,
        ZoneNPC,
        ZoneIssue,
        ZoneEventSubject,
        GlobalBoss,
        GlobalProfession,
        GlobalFaction,
        GlobalRace,
        GlobalClass,
        GlobalTheme,
        InGameTime,
        CurrentWeather
    };

    struct ConversationTopic
    {
        ConversationTopicCategory     category;
        ConversationTopicSubCategory  subCategory;
        std::string                   formatTemplate;
        TopicDataSource               dataSource;
    };

    struct ConversationGenAIState
    {
        std::atomic<bool> ready{ false };
        std::string result;
        std::mutex mutex;
    };

    // -------------------------------------------------------------------------
    // Global data tables
    // -------------------------------------------------------------------------

    inline const std::vector<std::string> Professions =
    {
        // Original professions
        "Engineering", "Alchemy", "Blacksmithing", "Tailoring",
        "Enchanting", "Leatherworking", "Jewelcrafting", "Inscription",
        "Cooking", "Fishing", "First Aid", "Herbalism", "Mining", "Skinning",

        // Gathering sub-skills & materials
        "Smelting", "Prospecting", "Milling", "Disenchanting",
        "Gathering Herbs", "Gathering Ore", "Gathering Leather",
        "Hard to find herb", "Rare herb", "Rare ore", "Rare fish",

        // Archaeology
        "Archaeology", "Fossil Fragment", "Night Elf Archaeology",
        "Dwarf Archaeology", "Troll Archaeology", "Tol'vir Archaeology",
        "Pandaren Archaeology", "Mantid Archaeology", "Ogre Archaeology",
        "Draenor Archaeology", "Artifact Fragment", "Solve Artifact",
        "Archaeology Digsite", "Archaeology Survey",

        // Mining: ores
        "Copper Ore", "Tin Ore", "Iron Ore", "Mithril Ore", "Thorium Ore",
        "Fel Iron Ore", "Adamantite Ore", "Khorium Ore", "Cobalt Ore",
        "Saronite Ore", "Titanium Ore", "Obsidium Ore", "Elementium Ore",
        "Ghost Iron Ore", "Blackrock Ore", "True Iron Ore",
        "Leystone Ore", "Felslate", "Monelite Ore", "Storm Silver Ore",
        "Osmenite Ore",

        // Smelting: bars
        "Copper Bar", "Bronze Bar", "Iron Bar", "Steel Bar", "Mithril Bar",
        "Thorium Bar", "Fel Iron Bar", "Adamantite Bar", "Khorium Bar",
        "Cobalt Bar", "Saronite Bar", "Titansteel Bar", "Ghost Iron Bar",
        "Trillium Bar", "True Steel Ingot", "Monelite Bar", "Storm Silver Bar",

        // Herbalism: herbs
        "Peacebloom", "Silverleaf", "Earthroot", "Mageroyal", "Briarthorn",
        "Stranglekelp", "Kingsblood", "Liferoot", "Fadeleaf", "Goldthorn",
        "Khadgar's Whisker", "Wintersbite", "Firebloom", "Purple Lotus",
        "Arthas' Tears", "Sungrass", "Blindweed", "Ghost Mushroom",
        "Gromsblood", "Dreamfoil", "Mountain Silversage", "Plaguebloom",
        "Icecap", "Black Lotus", "Felweed", "Dreaming Glory", "Ragveil",
        "Netherbloom", "Nightmare Vine", "Mana Thistle", "Goldclover",
        "Tiger Lily", "Talandra's Rose", "Lichbloom", "Icethorn",
        "Cinderbloom", "Stormvine", "Azshara's Veil", "Heartblossom",
        "Twilight Jasmine", "Whiptail", "Green Tea Leaf", "Snow Lily",
        "Fool's Cap", "Fireweed", "Starflower", "Gorgrond Flytrap",
        "Nagrand Arrowbloom", "Talador Orchid", "Yseralline Seed",
        "Aethril", "Dreamleaf", "Fjarnskaggl", "Starlight Rose",
        "Astral Glory", "Riverbud", "Sea Stalk", "Siren's Pollen",
        "Anchor Weed",

        // Fishing: fish & locations
        "Fishing in Stranglethorn", "Fishing in Northrend", "Fishing in Pandaria",
        "Fishing in Outland", "Fishing in Zandalar", "Fishing in Kul Tiras",
        "Deviate Fish", "Stonescale Eel", "Oily Blackmouth", "Firefin Snapper",
        "Golden Carp", "Frenzied Fangtooth", "Great Sea Catfish",
        "Midnight Salmon", "Rare fish", "Special fishing pool",

        // Leatherworking: hides & scales
        "Light Leather", "Medium Leather", "Heavy Leather", "Thick Leather",
        "Rugged Leather", "Knothide Leather", "Borean Leather",
        "Savage Leather", "Exotic Leather", "Stonehide Leather",
        "Stormscale", "Coarse Leather", "Desolate Leather",

        // Tailoring: cloths
        "Linen Cloth", "Wool Cloth", "Silk Cloth", "Mageweave Cloth",
        "Runecloth", "Netherweave Cloth", "Frostweave Cloth",
        "Embersilk Cloth", "Windwool Cloth", "Sumptuous Fur",
        "Shal'dorei Silk", "Deep Sea Satin",

        // Enchanting: dusts & shards
        "Strange Dust", "Soul Dust", "Vision Dust", "Dream Dust",
        "Arcane Dust", "Infinite Dust", "Spirit Dust", "Draenic Dust",
        "Luminous Shard", "Small Brilliant Shard", "Large Brilliant Shard",
        "Heavenly Shard", "Eternal Crystal", "Veiled Crystal",

        // Jewelcrafting: gems
        "Prospecting Ore", "Cut Gem", "Uncut Gem", "Rare Gem",
        "Shadowgem", "Malachite", "Tigerseye", "Jade", "Citrine",
        "Aquamarine", "Star Ruby", "Huge Emerald", "Sapphire",
        "Primordial Ruby", "Sun's Radiance", "Wild Jade",
        "Imperial Amethyst", "Pandarian Garnet",

        // Inscription: pigments & inks
        "Milling Herbs", "Pigment", "Ink", "Warbinder's Ink",
        "Starlight Ink", "Ink of Dreams", "Cerulean Pigment",

        // Cooking: foods
        "Cooking Recipe", "Rare Cooking Ingredient", "Fish Feast",
        "Savory Deviate Delight", "Feast of the Waters", "Feast of the Winds",

        // Engineering: gadgets
        "Sprocket", "Cogwheel", "Gyrochronatom", "Volatile Trigger",
        "Engineering Device", "Explosive", "Gnomish Engineering",
        "Goblin Engineering",

        // Blacksmithing: patterns & materials
        "Blacksmithing Plans", "Weapon Chain", "Sharpening Stone",
        "Grinding Stone", "Rare Blacksmith Recipe",

        // Profession-related zones
        "Sholazar Basin Mining", "Un'Goro Crater Herb", "Zangarmarsh Fishing",
        "Storm Peaks Mining", "Nagrand Herb", "Zuldazar Herb",
        "Nazjatar Fishing", "Highmountain Mining"
    };

    inline const std::vector<std::string> Factions =
    {
        // Original entries
        "the Alliance", "the Horde", "the Burning Legion", "the Scourge",
        "the Old Gods", "the Argent Dawn", "the Kirin Tor", "the Earthen Ring",
        "the Dragonflights", "the Illidari", "the Scarlet Crusade", "the Defias Brotherhood",

        // Classic factions
        "Stormwind", "Ironforge", "Gnomeregan Exiles", "Darnassus", "Exodar",
        "Orgrimmar", "Thunder Bluff", "Undercity", "Darkspear Trolls", "Silvermoon City",
        "Booty Bay", "Everlook", "Gadgetzan", "Ratchet", "the Steamwheedle Cartel",
        "the Timbermaw Hold", "the Cenarion Circle", "the Hydraxian Waterlords",
        "the Zandalar Tribe", "the Shen'dralar", "the Brood of Nozdormu",

        // TBC factions
        "the Aldor", "the Scryers", "the Sha'tar", "the Sha'tari Skyguard",
        "the Netherwing", "the Ogri'la", "the Consortium", "the Kurenai",
        "the Mag'har", "the Ashtongue Deathsworn", "the Scale of the Sands",
        "the Keepers of Time",

        // Wrath factions
        "the Argent Crusade", "the Knights of the Ebon Blade", "the Sons of Hodir",
        "the Wyrmrest Accord", "the Kirin Tor Offensive", "the Frenzyheart Tribe",
        "the Oracles", "the Ashen Verdict",

        // Cataclysm factions
        "the Guardians of Hyjal", "the Ramkahen", "the Wildhammer Clan",
        "the Dragonmaw Clan", "the Therazane", "the Baradin's Wardens",
        "the Hellscream's Reach",

        // Mists of Pandaria factions
        "the Golden Lotus", "the Shado-Pan", "the August Celestials",
        "the Klaxxi", "the Order of the Cloud Serpent", "the Tillers",
        "the Anglers", "the Lorewalkers", "the Black Prince",

        // Warlords of Draenor factions
        "the Frostwolf Orcs", "the Laughing Skull", "the Sha'tari Defense",
        "the Council of Exarchs", "the Arakkoa Outcasts", "the Steamwheedle Preservation Society",

        // Legion factions
        "the Nightfallen", "the Court of Farondis", "the Dreamweavers",
        "the Highmountain Tribe", "the Valarjar", "the Wardens",
        "the Armies of Legionfall", "the Argussian Reach", "the Army of the Light",

        // Battle for Azeroth factions
        "the Proudmoore Admiralty", "the Order of Embers", "the Storm's Wake",
        "the Zandalari Empire", "the Voldunai", "the Talanji's Expedition",
        "the Champions of Azeroth", "the Tortollan Seekers",
        "the Rustbolt Resistance", "the Waveblade Ankoan", "the Unshackled",

        // Shadowlands factions
        "the Kyrian", "the Necrolords", "the Night Fae", "the Venthyr",
        "the Court of Harvesters", "the Ascended", "the Undying Army",
        "the Wild Hunt", "the Archivists' Codex", "the Death's Advance",

        // Dragonflight factions (renown)
        "the Dragonscale Expedition", "the Maruuk Centaur", "the Iskaara Tuskarr",
        "the Valdrakken Accord", "the Loamm Niffen", "the Soridormi",
        "the Dream Wardens",

        // Goblin cartels & pirate crews
        "the greedy Booty Bay goblins", "the Bloodsail Buccaneers",
        "the Venture Company", "the Steamwheedle Cartel", "the Bilgewater Cartel",

        // Rare mount factions
        "the Netherwing Drake Riders", "the Order of the Cloud Serpent",
        "the Argent Tournament", "the Rustbolt Resistance",
        "the Nightfallen Mana Sabers", "the Highmountain Thunderhoof",
        "the Zandalari Warbringers", "the Shadowmoon Exiles",

        // Lore conflict factions
        "the Scryers at war with the Aldor", "the Defias uprising",
        "the Scarlet Onslaught", "the Twilight's Hammer",
        "the Cult of the Damned", "the Primalists", "the Infinite Dragonflight",

        // Dragonflights (expanded)
        "the Red Dragonflight", "the Blue Dragonflight", "the Green Dragonflight",
        "the Bronze Dragonflight", "the Black Dragonflight", "the Netherwing Flight",

        // Misc lore factions
        "the Explorers' League", "the Reliquary", "the Silver Covenant",
        "the Sunreavers", "the Darkmoon Faire", "the Cenarion Expedition",
        "the Earthen", "the Dracthyr", "the Tuskarr Tribes",
        "the Kalu'ak", "the Taunka", "the Frostborn",

        // Creative faction-related concepts
        "renown factions of the Dragon Isles", "ancient titan watchers",
        "the primal elemental cults", "the goblin trade princes",
        "the pirate crews of the South Seas", "the outlaw syndicates of Azeroth",
        "the dragonflights vying for power", "the rival clans of Draenor",
        "the covenants of the Shadowlands", "the ancient kaldorei orders"
    };

    inline const std::vector<std::string> Themes =
    {
        // Original themes
        "profession", "boss", "weapon", "mount", "hero", "villain",
        "zone", "dungeon", "race", "class", "spell", "armor", "pet", "faction",

        // Gameplay systems
        "renown", "reputation grind", "world quest", "mythic plus",
        "raid progression", "open world exploration", "crafting system",
        "talent trees", "class fantasy", "transmog collecting",
        "achievement hunting", "rare hunting", "mount farming",
        "pet battling", "auction house trading",

        // Major WoW events & story arcs
        "the Burning Crusade", "the Scourge invasion", "the Cataclysm",
        "the Pandaria awakening", "the Legion invasion",
        "the Fourth War", "the Shadowlands crisis",
        "the Dragon Isles awakening", "the War of the Ancients",
        "the Sundering", "the War of the Three Hammers",
        "the fall of Arthas", "the rise of Deathwing",
        "the Siege of Orgrimmar", "the fall of Garrosh",
        "the Emerald Nightmare", "the Old God corruption",
        "the Black Empire", "the First Ones",

        // Cosmic themes
        "Light versus Void", "Order versus Disorder",
        "Life versus Death", "the cosmic forces",
        "the Shadowlands", "the Emerald Dream",
        "the Twisting Nether", "the Great Dark Beyond",

        // Dragonflight themes
        "dragonflight legacies", "ancient titan constructs",
        "elemental storms", "primalist invasions",
        "wyrmrest diplomacy", "dragonriding progression",
        "the return of the Aspects",

        // Shadowlands themes
        "covenant powers", "soulbinding", "anima drought",
        "the Maw", "Torghast", "the Jailer's schemes",
        "afterlife realms", "eternal ones",

        // BfA themes
        "azerite corruption", "warfronts", "island expeditions",
        "old god whispers", "the Black Empire rising",
        "kul tiran witchcraft", "zandalari loa worship",

        // Legion themes
        "artifact weapons", "class halls", "demon invasions",
        "fel corruption", "the Broken Shore", "the Argus campaign",

        // MoP themes
        "sha corruption", "pandaren philosophy", "mantid swarms",
        "celestial trials", "the Vale of Eternal Blossoms",

        // Cata themes
        "elemental unrest", "the shattering", "twilight cultists",
        "deepholm rifts", "ancient dragon conflicts",

        // Wrath themes
        "the Lich King's plague", "northrend exploration",
        "titan facilities", "vrykul mythology", "dragon sanctums",

        // TBC themes
        "fel-scarred outland", "shattered worlds", "netherstorm anomalies",
        "the naaru", "the blood elf addiction",

        // Classic themes
        "old world exploration", "vanilla raiding", "classic class identity",
        "scarlet crusade zealotry", "defias rebellion",

        // Seasonal & world events
        "Hallow's End", "Winter Veil", "Noblegarden", "Midsummer Fire Festival",
        "Darkmoon Faire", "Brewfest", "Love is in the Air",
        "Timewalking events", "world invasions",

        // Social & worldbuilding themes
        "goblin greed", "dwarven craftsmanship", "night elf druidism",
        "tauren shamanism", "blood elf arcane addiction",
        "forsaken alchemy", "pandaren harmony",
        "troll loa worship", "orcish honor",
        "draenei lightforging", "void elf transformation",

        // Conflict themes
        "Horde versus Alliance", "civil war", "betrayal arcs",
        "ancient rivalries", "faction pride", "political intrigue",
        "sieges and assaults", "world-ending threats",

        // Exploration & world themes
        "lost civilizations", "titan ruins", "forgotten kingdoms",
        "ancient prophecies", "hidden zones", "secret puzzles",
        "rare treasures", "elite world bosses"
    };

    inline const std::vector<std::string> BossNames =
    {
        // Your originals
        "Ragnaros", "Onyxia", "Illidan Stormrage", "The Lich King",
        "Deathwing", "Garrosh Hellscream", "Sylvanas Windrunner",
        "Kel'Thuzad", "C'Thun", "Nefarian", "Malygos", "Yogg-Saron",
        "Archimonde", "Kil'jaeden", "Gul'dan", "Varimathras",
        "Lord Kazzak", "Azuregos", "Emeriss", "Nightsong", "Hogger",

        // Classic raid bosses
        "Majordomo Executus", "Baron Geddon", "Gehennas", "Lucifron",
        "Chromaggus", "Vaelastrasz the Corrupt", "Broodlord Lashlayer",
        "Hakkar the Soulflayer", "Ossirian the Unscarred",

        // Classic dungeon bosses
        "Edwin VanCleef", "Moroes", "Arugal", "Thermaplugg",
        "Princess Theradras", "Emperor Thaurissan",

        // Holiday & special bosses
        "the evil Headless Horseman", "the wicked Lord Ahune",
        "the sinister Crown Chemical Trio", "the mischievous Greatfather Winter's Abomination",
        "the cruel Coren Direbrew",

        // TBC raid bosses
        "Lady Vashj", "Kael'thas Sunstrider", "Magtheridon",
        "Gruul the Dragonkiller", "High King Maulgar",
        "Mother Shahraz", "Gurtogg Bloodboil", "Teron Gorefiend",
        "Illidari Council", "Supremus", "Reliquary of Souls",

        // TBC dungeon bosses
        "Murmur", "Pathaleon the Calculator", "Warlord Kalithresh",
        "Exarch Maladaar", "Keli'dan the Breaker",

        // Wrath raid bosses
        "Anub'arak", "Mimiron", "Freya", "Thorim", "Hodir",
        "General Vezax", "Sindragosa", "Professor Putricide",
        "Blood-Queen Lana'thel", "Sartharion", "Halion",

        // Wrath dungeon bosses
        "Loken", "Keristrasza", "Ingvar the Plunderer",
        "King Ymiron", "Skadi the Ruthless",

        // Cata raid bosses
        "Cho'gall", "Al'Akir", "Nefarian (Cataclysm)", "Sinestra",
        "Ragnaros the Firelord (Heroic)", "Morchok", "Ultraxion",
        "Madness of Deathwing", "Warlord Zon'ozz", "Yor'sahj the Unsleeping",

        // Cata dungeon bosses
        "Ozumat", "High Priestess Azil", "Erudax",

        // MoP raid bosses
        "Lei Shen", "Sha of Fear", "Sha of Pride", "Garalon",
        "Will of the Emperor", "Elegon", "Durumu the Forgotten",
        "Dark Animus", "Siegecrafter Blackfuse", "Paragons of the Klaxxi",

        // MoP dungeon bosses
        "Wise Mari", "Lorewalker Stonestep", "Taran Zhu",

        // WoD raid bosses
        "Blackhand", "Kargath Bladefist", "Imperator Mar'gok",
        "Gorefiend (WoD)", "Kilrogg Deadeye", "Mannoroth (WoD)",
        "Archimonde (WoD)", "Operator Thogar", "Hans'gar and Franzok",

        // Legion raid bosses
        "Xavius", "Ursoc", "Cenarius", "Helya",
        "Gul'dan (Nighthold)", "Star Augur Etraeus",
        "Elisande", "Kil'jaeden (Tomb of Sargeras)",
        "Fallen Avatar", "Argus the Unmaker",

        // Legion dungeon bosses
        "Cordana Felsong", "Ymiron (Legion)", "Helya (Dungeon)",

        // BfA raid bosses
        "G'huun", "Mythrax the Unraveler", "MOTHER",
        "Zek'voz", "Lady Jaina Proudmoore", "Uu'nat",
        "Queen Azshara", "N'Zoth the Corruptor",

        // BfA dungeon bosses
        "Vol'kaal", "Rezan", "Lord Stormsong", "Skycap'n Kragg",

        // Shadowlands raid bosses
        "Sire Denathrius", "Stone Legion Generals", "Sludgefist",
        "The Tarragrue", "Sylvanas Windrunner (Sanctum)",
        "Kel'Thuzad (SL)", "The Jailer", "Lords of Dread",
        "Rygelon", "Anduin Wrynn (Raid)",

        // Shadowlands dungeon bosses
        "Dealer Xy'exa", "Hakkar the Soulflayer (SL)", "Mueh'zala",

        // Dragonflight raid bosses
        "Raszageth the Storm-Eater", "Kurog Grimtotem",
        "Broodkeeper Diurna", "Scalecommander Sarkareth",
        "Fyrakk the Blazing", "Tindral Sageswift",
        "Smolderon", "Volcoross",

        // Dragonflight dungeon bosses
        "Melidrussa Chillworn", "Balakar Khan", "Teera and Maruuk",

        // World bosses (all eras)
        "Oondasta", "Nalak", "Sha of Anger", "Galleon",
        "Rukhmar", "Doomwalker", "Kazzak (WoD)", "Ivus the Forest Lord",
        "Vyranoth (Encounter)", "Aurostor the Hibernating",

        // Fun, flavorful descriptors
        "the wicked Witch of the Wastes", "the cruel Bone Lord",
        "the mad Arcanist", "the twisted Flesh-Shaper",
        "the sinister Soulbinder", "the corrupted Titan Keeper",
        "the ancient Worldbreaker", "the forgotten Old God Herald",
        "the malevolent Spiritcaller", "the dread Necromancer King"
    };

    // -------------------------------------------------------------------------
    // Zone-local data tables (zoneId -> keyword list)
    // -------------------------------------------------------------------------
    inline const std::unordered_map<uint32, std::vector<std::string>> ZoneFeatures =
    {
        {   12, {
            "the wolves", "Goldshire", "the Eastvale Logging Camp", "the roads",
            "the Fargodeep Mine", "the kobolds shouting 'You no take candle!'",
            "the peaceful farmlands", "the Stormwind guards on patrol"
        }}, // Elwynn Forest

        { 1519, {
            "the canals", "the Mage Quarter", "the Auction House", "the Cathedral",
            "the Dwarven District", "the Park ruins", "the bustling trade district",
            "the gryphon roost", "the heroic statues at the gates"
        }}, // Stormwind

        {    1, {
            "the trolls", "the Coldridge Pass", "the brewery", "the tram",
            "the snow-covered peaks", "the Frostmane trolls", "the frozen lakes",
            "the dwarven hunters", "the chilly winds"
        }}, // Dun Morogh

        { 1537, {
            "the Great Forge", "the Mystic Ward", "the auctioneers", "the tram station",
            "the Hall of Explorers", "the military ward", "the molten rivers",
            "the clanging forges", "the dwarven craftsmanship"
        }}, // Ironforge

        {   14, {
            "the scorpions", "Razor Hill", "the troll village", "the beach",
            "the burning sun", "the quillboar camps", "the echoing war drums",
            "the jagged red cliffs", "the dusty canyons"
        }}, // Durotar

        { 1637, {
            "the Valley of Strength", "the drag", "the bank", "the warchief",
            "the Cleft of Shadow", "the zeppelin towers", "the roaring fires",
            "the warrior training grounds", "the bustling marketplace"
        }}, // Orgrimmar

        {   85, {
            "the Scarlet Crusade", "the Brill road", "the graveyard", "the plague",
            "the undead wandering fields", "the ruined farms", "the eerie silence",
            "the looming Gallows' End", "the creeping fog"
        }}, // Tirisfal Glades

        { 1497, {
            "the Apothecarium", "the Royal Quarter", "the sewers", "the abominations",
            "the eerie green glow", "the endless corridors", "the banshee guards",
            "the alchemical fumes", "the whispering shadows"
        }}, // Undercity

        {  141, {
            "the giant trees", "the spiders", "Aldrassil", "the moonwell",
            "the nightsaber prowlers", "the ancient elven ruins", "the soft purple glow",
            "the tranquil forest paths"
        }}, // Teldrassil

        { 1657, {
            "the Temple of the Moon", "the Craftsmen's Terrace", "the bank", "the portals",
            "the whispering ancients", "the sentinel guards", "the shimmering waters",
            "the peaceful gardens"
        }}, // Darnassus

        {  148, {
            "the murlocs", "the beach", "the ruins", "the twilight cultists",
            "the ancient kaldorei structures", "the storm-battered coastline",
            "the restless spirits", "the corrupted wildlife"
        }}, // Darkshore

        {   40, {
            "the Defias Brotherhood", "the farms", "the harvest golems", "the lighthouse",
            "the homeless refugees", "the dusty plains", "the abandoned mines",
            "the roaming gnolls", "the dramatic sunsets"
        }}, // Westfall

        {   44, {
            "the gnolls", "the bridge", "Lake Everstill", "the orcs",
            "the Redridge militia", "the Blackrock raiders", "the burning farms",
            "the tranquil lakeside cabins"
        }}, // Redridge Mountains

        {   10, {
            "the worgen", "the dark woods", "Raven Hill", "the necromancers",
            "the eerie fog", "the restless dead", "the haunted cemetery",
            "the lurking spiders", "the ominous atmosphere"
        }}, // Duskwood

        {   38, {
            "the loch", "the troggs", "the dam", "the excavators",
            "the dwarven dig sites", "the shimmering waters", "the mountain goats",
            "the stout defenders"
        }}, // Loch Modan

        {   17, {
            "the centaur", "the crossroads", "the oasis", "the harpies",
            "the quillboar ambushes", "the roaming kodos", "the burning plains",
            "the goblin caravans"
        }}, // Northern Barrens

        { 3524, {
            "the draenei crash site", "the irradiated wildlife", "the crystal forests",
            "the ancient ruins", "the glowing blue flora", "the Stillpine furbolgs",
            "the Exodar fragments"
        }}, // Azuremyst Isle

        { 3525, {
            "the blood elves", "the corrupted wildlife", "the red crystal fields",
            "the naga camps", "the irradiated pools", "the draenei survivors",
            "the eerie crimson glow"
        }}, // Bloodmyst Isle

        { 3430, {
            "the golden forests", "the mana wyrms", "the spire towers",
            "the Farstrider Retreat", "the arcane guardians", "the tranquil music",
            "the majestic elven architecture"
        }}, // Eversong Woods (Burning Crusade)

        { 3433, {
            "the ghostly woods", "the Scourge remnants", "the fallen elven towers",
            "the Deatholme fortress", "the spectral banshees", "the corrupted wildlife",
            "the eerie crimson haze"
        }}, // Ghostlands

        { 130, {
            "the worgen packs", "the shadowy forests", "the Forsaken patrols",
            "the ruined keeps", "the creeping fog", "the haunted coastline",
            "the Gilnean refugees"
        }}, // Silverpine Forest

        { 215, {
            "the rolling plains", "the peaceful kodos", "Thunder Bluff totems",
            "the tauren tribes", "the golden grasslands", "the wandering braves",
            "the sacred Red Rocks"
        }}, // Mulgore

        { 16, {
            "the goblin experiments", "the twisted cliffs", "the arcane storms",
            "the naga invasion", "the lightning-scarred beaches", "the floating ruins",
            "the goblin rocketways"
        }}, // Azshara

        { 5339, {
            "the jungle trolls", "the pirates", "the Gurubashi Arena",
            "the dense rainforest", "the giant tigers", "the ancient ruins",
            "the treasure hunters", "the humid heat"
        }}, // Stranglethorn Vale
    };

    inline const std::unordered_map<uint32, std::vector<std::string>> ZoneNPCs =
    {
        {   12, {
            "Marshal McBride", "Remy Two-Times", "Falkhaan Isenstrider", "Smith Argus",
            "Brother Paxton", "Deputy Rainer", "Guard Thomas", "Maybell Maclure"
        }}, // Elwynn Forest

        { 1519, {
            "King Varian Wrynn", "Anduin Wrynn", "Gryan Stoutmantle", "Archbishop Benedictus",
            "Highlord Bolvar Fordragon", "Master Mathias Shaw", "Old Town Guard Berton",
            "Maginor Dumas"
        }}, // Stormwind

        {    1, {
            "Captain Tharran", "Bruuk Barleybeard", "Sten Stoutarm", "Rejold Barleybrew",
            "Grelin Whitebeard", "Nori Pridedrift", "Hands Springsprocket", "Senir Whitebeard"
        }}, // Dun Morogh

        { 1537, {
            "Magni Bronzebeard", "High Tinker Mekkatorque", "Grumnus Steelshaper", "Belgrum",
            "Historian Karnik", "Prospector Stormpike", "Innkeeper Firebrew", "King Magni's Guards"
        }}, // Ironforge

        {   14, {
            "Gar'thok", "Lar Prowltusk", "Rezlak", "Ophek",
            "Gornek", "Kaltunk", "Master Gadrin", "Vol'jin"
        }}, // Durotar

        { 1637, {
            "Thrall", "Cairne Bloodhoof", "Vol'jin", "Sylvanas Windrunner",
            "Garrosh Hellscream", "Overlord Runthak", "Innkeeper Gryshka", "Jorin Deadeye"
        }}, // Orgrimmar

        {   85, {
            "Novice Thaivand", "Executor Zygand", "Apothecary Johaan", "Magistrate Sevren",
            "Deathguard Dillinger", "Deathguard Simmer", "Coleman Farthing", "Calvin Montague"
        }}, // Tirisfal Glades

        { 1497, {
            "Sylvanas Windrunner", "Varimathras", "Apothecary Faranell", "Lady Sylvanas",
            "Master Apothecary Lydon", "High Executor Hadrec", "Dark Cleric Beryl",
            "Royal Overseer Bauhaus"
        }}, // Undercity

        {  141, {
            "Tenaron Stormgrip", "Athridas Bearmantle", "Dirania Silvershine", "Ilthalaine",
            "Conservator Ilthalaine", "Zenn Foulhoof", "Alyissia", "Shanda the Spinner"
        }}, // Teldrassil

        { 1657, {
            "Tyrande Whisperwind", "Malfurion Stormrage", "Elune", "Belysra Starbreeze",
            "Arch Druid Fandral Staghelm", "Sentinel Thenysil", "Innkeeper Saelienne",
            "Priestess Alathea"
        }}, // Darnassus

        {  148, {
            "Sentinel Tysha Moonblade", "Thundris Windweaver", "Terenthis", "Asterion",
            "Onu", "Cerellean Whiteclaw", "Volcor", "Gorbold Steelhand"
        }}, // Darkshore

        {   40, {
            "Gryan Stoutmantle", "Farmer Saldean", "Scout Galiaan", "Captain Danuvin",
            "Old Murk-Eye", "Captain Grayson", "Innkeeper Heather", "Lieutenant Horatio Laine"
        }}, // Westfall

        {   44, {
            "Magistrate Solomon", "Marshal Marris", "Guard Parker", "Foreman Oslow",
            "Watcher Dodds", "Chef Breanna", "Deputy Feldon", "Blackrock Outrunner"
        }}, // Redridge Mountains

        {   10, {
            "Abercrombie", "Clerk Daltry", "Jitters", "Elaine Carevin",
            "Commander Althea Ebonlocke", "Sven Yorgen", "Mor'Ladim", "Watcher Morgan"
        }}, // Duskwood

        {   38, {
            "Mountaineer Stormpike", "Pilot Bellowfiz", "Prospector Ironband", "Merrin Rockweaver",
            "Mountaineer Kadrell", "Mountaineer Gravelgaw", "Chief Engineer Hinderweir",
            "The Loch Crocolisks"
        }}, // Loch Modan

        {   17, {
            "Sergra Darkthorn", "Tonga Runetotem", "Mankrik", "Zargh",
            "Gazrog", "Regthar Deathgate", "Barak Kodobane", "Brewmaster Drohn"
        }}, // Northern Barrens

        { 3524, {
            "Prophet Velen", "High Chief Stillpine", "Admiral Odesyus", "Technician Dyvuun",
            "Priestess Kyleen Il'dinare", "Arugoo of the Stillpine", "Vindicator Aldar",
            "Morae"
        }}, // Azuremyst Isle

        { 3525, {
            "Exarch Menelaous", "Vindicator Kuros", "Vindicator Aalesia", "Harbinger Mikolaas",
            "Prince Toreth", "Captain Edward Hanes", "Jessera of Mac'Aree",
            "Tracker Lyceon"
        }}, // Bloodmyst Isle

        { 3430, {
            "Lor'themar Theron", "Ranger General Halduron Brightwing", "Magister Jaronis",
            "Instructor Antheol", "Ranger Degolien", "Aeldon Sunbrand",
            "Arcanist Helion", "Prospector Anvilward"
        }}, // Eversong Woods (Burning Crusade)

        { 3433, {
            "Ranger Valanna", "Ranger Lilatha", "High Executor Mavren", "Apothecary Renzithen",
            "Deathstalker Rathiel", "Magister Sylastor", "Arcanist Vandril",
            "Dar'Khan Drathir"
        }}, // Ghostlands

        { 130, {
            "Sylvanas Windrunner", "Darius Crowley", "Ivar Bloodfang", "High Executor Hadrec",
            "Shadow Priest Allister", "Deathstalker Vincent", "Apothecary Renferrel",
            "Lord Godfrey"
        }}, // Silverpine Forest

        { 215, {
            "Baine Bloodhoof", "Chief Hawkwind", "Greatmother Hawkwind", "Seer Graytongue",
            "Innkeeper Kauth", "Ruul Eagletalon", "Maur Raincaller", "Skorn Whitecloud"
        }}, // Mulgore

        { 16, {
            "Archmage Xylem", "Auberdine Sentinel", "Captain Grunwald", "Teemo",
            "Narain Soothfancy", "The Duke of Cynders", "Legion Overseer",
            "Servant of Azshara"
        }}, // Azshara

        { 5339, {
            "Hemet Nesingwary", "Barnil Stonepot", "Hemet Jr.", "Sir S. J. Erlgadin",
            "Bloodlord Mandokir", "High Priestess Jeklik", "Chief Ukorz Sandscalp",
            "Fleet Master Seahorn"
        }}, // Stranglethorn Vale
    };

    inline const std::unordered_map<uint32, std::vector<std::string>> ZoneIssues =
    {
        {   12, {
            "the wolves", "the long walks", "the lack of a real inn",
            "Goldshire drama", "the kobolds stealing candles", "the guards doing nothing"
        }}, // Elwynn Forest

        { 1519, {
            "the canal smell", "the crowds", "the expensive repairs",
            "the lag in the Auction House", "the nobles judging you", "the gryphon poop everywhere"
        }}, // Stormwind

        {    1, {
            "the cold", "the trolls", "the long tunnels",
            "the constant snow blindness", "the frozen beer", "the goats blocking the roads"
        }}, // Dun Morogh

        { 1537, {
            "the noise", "the smoke", "the gnomes arguing",
            "the heat from the forge", "the confusing layout", "the echoing footsteps"
        }}, // Ironforge

        {   14, {
            "the heat", "the scorpions", "the dry wind",
            "the dust storms", "the quillboar ambushes", "the cracked lips"
        }}, // Durotar

        { 1637, {
            "the smell", "the crowds", "the warchief's temper",
            "the cramped alleys", "the constant yelling", "the zeppelin delays"
        }}, // Orgrimmar

        {   85, {
            "the undead", "the smell", "the Scarlet fanatics",
            "the fog", "the creepy silence", "the constant moaning (and not the fun kind)"
        }}, // Tirisfal Glades

        { 1497, {
            "the sewers", "the abominations", "the gloom",
            "the green slime puddles", "the echoing screams", "the smell of rot"
        }}, // Undercity

        {  141, {
            "the spiders", "the height", "the endless branches",
            "the purple haze", "the confusing paths", "the owls staring at you"
        }}, // Teldrassil

        { 1657, {
            "the isolation", "the burning tree", "the night-only schedule",
            "the whispering ancients", "the slow elevators", "the constant moonlight glare"
        }}, // Darnassus

        {  148, {
            "the murlocs", "the rain", "the cultists",
            "the washed-up debris", "the gloomy skies", "the constant shipwrecks"
        }}, // Darkshore

        {   40, {
            "the Defias", "the dust", "the broken farms",
            "the homeless people everywhere", "the scarecrows staring at you",
            "the constant wind howling"
        }}, // Westfall

        {   44, {
            "the gnolls", "the bridge toll", "the orc raids",
            "the constant smoke from Lakeshire", "the wet boots", "the wolves howling all night"
        }}, // Redridge Mountains

        {   10, {
            "the worgen", "the darkness", "the undead",
            "the fog that never lifts", "the creepy children", "the spiders the size of horses"
        }}, // Duskwood

        {   38, {
            "the troggs", "the dam noise", "the cold water",
            "the constant construction", "the echoing explosions", "the soggy boots"
        }}, // Loch Modan

        {   17, {
            "the centaur", "the heat", "the long roads",
            "the dust storms", "the quillboar ambushes", "the kodos blocking traffic"
        }}, // Northern Barrens

        { 3524, {
            "the crashed spaceship debris", "the glowing crystals everywhere",
            "the mutated wildlife", "the constant buzzing noises",
            "the draenei architecture blinding your eyes", "the weird purple fog"
        }}, // Azuremyst Isle

        { 3525, {
            "the radiation", "the red crystals", "the corrupted wildlife",
            "the constant naga attacks", "the eerie silence", "the blood elves spying on you"
        }}, // Bloodmyst Isle

        { 3430, {
            "the mana wyrms biting your ankles", "the smug blood elves",
            "the constant magical humming", "the arcane guardians judging you",
            "the blinding golden sunlight", "the teleporters that never go where you expect"
        }}, // Eversong Woods (Burning Crusade)

        { 3433, {
            "the ghosts", "the Scourge leftovers", "the creepy red fog",
            "the ruined buildings", "the banshees screaming at night",
            "the spiders dropping from trees"
        }}, // Ghostlands

        { 130, {
            "the worgen ambushes", "the fog", "the Forsaken patrols",
            "the ruined keeps", "the howling wind", "the constant dread"
        }}, // Silverpine Forest

        { 215, {
            "the endless plains", "the kodo droppings", "the windstorms",
            "the long walks", "the lack of shade", "the prairie dogs stealing food"
        }}, // Mulgore

        { 16, {
            "the goblin pollution", "the unstable cliffs", "the arcane storms",
            "the naga everywhere", "the lightning strikes", "the goblin shouting"
        }}, // Azshara

        { 5339, {
            "the humidity", "the tigers stalking you", "the trolls yelling",
            "the pirates shooting cannons", "the mosquitoes the size of bats",
            "the jungle rot"
        }}, // Stranglethorn Vale
    };

    inline const std::unordered_map<uint32, std::vector<std::string>> ZoneEventSubjects =
    {
        {   12, {
            "a wolf attack", "a lost shipment", "a traveling merchant",
            "a kobold uprising", "a Goldshire bar fight", "a candle-stealing spree",
            "a runaway horse", "a suspicious scarecrow"
        }}, // Elwynn Forest

        { 1519, {
            "a canal incident", "a mage experiment", "a guard chase",
            "a gryphon mishap", "a rogue pickpocket spree", "a noble scandal",
            "a sewer overflow", "a magical explosion in the Mage Quarter"
        }}, // Stormwind

        {    1, {
            "a cave-in", "a troll raid", "a brewing accident",
            "a snowstorm warning", "a lost mountaineer", "a frozen keg emergency",
            "a mechanical squirrel malfunction"
        }}, // Dun Morogh

        { 1537, {
            "a forge explosion", "a gnome invention", "a council debate",
            "a runaway shredder", "a malfunctioning tram", "a beer shortage panic",
            "a heated argument in the Hall of Explorers"
        }}, // Ironforge

        {   14, {
            "a scorpion swarm", "a shipwreck", "a vision quest",
            "a quillboar ambush", "a dust storm", "a rogue kodo stampede",
            "a troll fire dance gone wrong"
        }}, // Durotar

        { 1637, {
            "a bar brawl", "a shaman ritual", "a trade dispute",
            "a zeppelin crash scare", "a duel in the Valley of Honor",
            "a goblin fireworks mishap", "a warchief proclamation"
        }}, // Orgrimmar

        {   85, {
            "a grave robbing", "a plague outbreak", "a Scarlet patrol",
            "a banshee wail heard across the fields", "a wandering abomination",
            "a necromantic surge", "a missing corpse report"
        }}, // Tirisfal Glades

        { 1497, {
            "an experiment gone wrong", "a sewer blockage", "a Forsaken rally",
            "a plague barrel leak", "a rogue abomination rampage",
            "a dark ritual in the Royal Quarter", "a missing apothecary"
        }}, // Undercity

        {  141, {
            "a spider infestation", "a moonwell disturbance", "a druid gathering",
            "a corrupted treant sighting", "a lost nightsaber cub",
            "a strange whisper from the forest", "a shadowy figure near Aldrassil"
        }}, // Teldrassil

        { 1657, {
            "a portal malfunction", "a crafting contest", "a Sentinel drill",
            "a moonlit ceremony", "a diplomatic envoy arrival",
            "a druidic vision", "a temple blessing gone awry"
        }}, // Darnassus

        {  148, {
            "a murloc raid", "a ship arrival", "a twilight sighting",
            "a beached sea creature", "a storm surge", "a corrupted treant rampage",
            "a mysterious light offshore"
        }}, // Darkshore

        {   40, {
            "a Defias ambush", "a harvest golem rampage", "a lighthouse signal",
            "a dust storm", "a missing farmer", "a wagon robbery",
            "a scarecrow coming to life"
        }}, // Westfall

        {   44, {
            "a gnoll attack", "a bridge collapse", "a black dragon sighting",
            "a militia drill", "a lake monster rumor", "a stolen shipment",
            "a Redridge cook-off gone wrong"
        }}, // Redridge Mountains

        {   10, {
            "a worgen howl", "a graveyard disturbance", "a necromancer ritual",
            "a ghostly apparition", "a missing villager", "a cursed artifact discovery",
            "a raven swarm"
        }}, // Duskwood

        {   38, {
            "a trogg breach", "a dam overflow", "a prospector discovery",
            "a cave collapse", "a runaway ram", "a dwarven excavation mishap",
            "a mysterious tremor"
        }}, // Loch Modan

        {   17, {
            "a centaur raid", "an oasis dispute", "a trade caravan arrival",
            "a quillboar uprising", "a kodo stampede", "a goblin racing event",
            "a rogue fire elemental"
        }}, // Northern Barrens

        { 3524, {
            "a crystal resonance", "a draenei scouting mission", "a mutated creature sighting",
            "a crashed pod discovery", "a Stillpine ritual", "a strange blue glow",
            "a vindicator patrol"
        }}, // Azuremyst Isle

        { 3525, {
            "a blood crystal surge", "a naga attack", "a corrupted wildlife incident",
            "a draenei distress signal", "a red storm anomaly", "a void-tainted creature",
            "a mysterious meteor fragment"
        }}, // Bloodmyst Isle

        { 3430, {
            "a mana wyrm swarm", "a Farstrider patrol", "a magical overload",
            "a Sunspire malfunction", "a ranger training drill", "a mana tap accident",
            "a phoenix hatchling escape"
        }}, // Eversong Woods (Burning Crusade)

        { 3433, {
            "a ghostly uprising", "a Scourge resurgence", "a Deatholme ritual",
            "a banshee scream heard across the woods", "a ranger distress call",
            "a corrupted crystal pulse", "a missing patrol"
        }}, // Ghostlands

        { 130, {
            "a worgen ambush", "a Forsaken patrol clash", "a dark ritual",
            "a Gilnean refugee sighting", "a creeping fog event",
            "a shadow beast attack", "a haunted manor disturbance"
        }}, // Silverpine Forest

        { 215, {
            "a kodo stampede", "a tribal gathering", "a spirit vision",
            "a thunderstorm omen", "a rogue prairie wolf pack",
            "a sacred totem theft", "a wandering elemental"
        }}, // Mulgore

        { 16, {
            "a naga ritual", "a goblin rocket malfunction", "an arcane storm",
            "a lightning surge", "a magical rift opening", "a rogue satyr sighting",
            "a goblin mining explosion"
        }}, // Azshara

        { 5339, {
            "a troll warband attack", "a pirate cannon barrage", "a jungle beast rampage",
            "a Gurubashi arena event", "a treasure hunter duel",
            "a giant gorilla sighting", "a mysterious drumbeat in the jungle"
        }}, // Stranglethorn Vale
    };

    ConversationTopic PickRandomTopic();
    std::string ResolveDataItem(Creature* bot, TopicDataSource source);
    std::string BuildTopicDescription(Creature* bot, ConversationTopic const& topic);
    std::string BuildConversationSystemPrompt(Creature* bot);
    void DispatchConversationTurn(Creature* speaker, FSBChat::ActiveConversation& conv);
}
