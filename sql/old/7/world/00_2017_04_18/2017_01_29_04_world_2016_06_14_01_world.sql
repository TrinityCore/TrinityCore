--
UPDATE `creature_template` SET `mechanic_immune_mask`= mechanic_immune_mask
|1 -- CHARM
|2 -- DISORIENTED
|4 -- DISARM
|8 -- DISTRACT
|16 -- FEAR
|32 -- GRIP
|64 -- ROOT
|256 -- SILENCE
|512 -- SLEEP
|1024 -- SNARE
|2048 -- STUN
|4096 -- FREEZE
|8192 -- KNOCKOUT
|65536 -- POLYMORPH
|131072 -- BANISH
|524288 -- SHACKLE
|4194304 -- TURN
|8388608 -- HORROR
|67108864 -- DAZE
|536870912 -- SAPPED
WHERE `entry` IN
-- Utgarde Keep
(23953,30748, -- Prince Keleseth
27390,31680, -- Skarvald the Constructor
27389,31657, -- Dalronn the Controller
23954,31673, -- Ingvar the Plunderer

-- The Nexus
26731,30510, -- Grand Magus Telestra
26763,30529, -- Anomalus
26794,30532, -- Ormorok the Tree-Shaper
26723,30540, -- Keristrasza
26796,30398, -- Commander Stoutbeard
26798,30397, -- Commander Kolurg

-- Azjol-Nerub
28684,31612, -- Krik'thir the Gatewatcher
28921,31611, -- Hadronox
29120,31610, -- Anub'arak

-- Ahn'kahet: The Old Kingdom
29309,31456, -- Elder Nadox
29308,31469, -- Prince Taldaram
29310,31465, -- Jedoga Shadowseeker
29311,31464, -- Herald Volazj
30258,31463, -- Amanitar

-- Drak'Tharon Keep
26630,31362, -- Trollgore
26631,31350, -- Novos the Summoner
27483,31349, -- King Dred
26632,31360, -- The Prophet Tharon'ja

-- The Violet Hold
29315,31507, -- Erekem
29316,31510, -- Moragg
29313,31508, -- Ichoron
29266,31511, -- Xevozz
29312,31509, -- Lavanthor
29314,31512, -- Zuramat the Obliterator
31134,31506, -- Cyanigosa

-- Gundrak
29304,31370, -- Slad'ran
29307,31365, -- Drakkari Colossus
29573,31367, -- Drakkari Elemental
29305,30530, -- Moorabi
29306,31368, -- Gal'darah
29932, -- Eck the Ferocious

-- Halls of Stone
27975,31384, -- Maiden of Grief
27977,31381, -- Krystallus
27978,31386, -- Sjonnir The Ironshaper

-- The Culling of Stratholme
26529,31211, -- Meathook
26530,31212, -- Salramm the Fleshcrafter
26532,31215, -- Chrono-Lord Epoch
26533,31217, -- Mal'Ganis
32273,32313, -- Infinite Corruptor

-- Halls of Lightning
28586,31533, -- General Bjarngrim
28587,31536, -- Volkhan
28546,31537, -- Ionar
28923,31538, -- Loken

-- The Oculus
27654,31558, -- Drakos the Interrogator
27447,31559, -- Varos Cloudstrider
27655,31560, -- Mage-Lord Urom
27656,31561, -- Ley-Guardian Eregos

-- Utgarde Pinnacle
26668,30810, -- Svala Sorrowgrave
26687,30774, -- Gortok Palehoof
26693,30807, -- Skadi the Ruthless
26861,30788, -- King Ymiron

-- The Forge of Souls
36497,36498); -- Bronjahm
