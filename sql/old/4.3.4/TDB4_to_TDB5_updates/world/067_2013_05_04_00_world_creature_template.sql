UPDATE `creature_template` SET `mechanic_immune_mask`=`mechanic_immune_mask`
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
(28859,31734, -- Malygos
39863,39864,39944,39945,40142,40143,40144,40145, -- Halion
39746,39805, -- General Zarithrian
39747,39823, -- Saviana Ragefire
39751,39899,39920,39922, -- Baltharus the Warborn
37025,38064,37217,38103,  -- Stinky & Precious
10184,36538, -- Onyxia
33113,34003, -- Flame Leviathan
33293,33885, -- XT-002 Deconstructor
32857,33694, -- Stormcaller Brundir
32927,33692, -- Runemaster Molgeim
32867,33693, -- Steelbreaker
32930,33909, -- Kologarn
32933,32934, -- Kologarn Arms
33515,34175, -- Auriaya
32906,33360, -- Freya
32915,33391, -- Elder Brightleaf
32914,33393, -- Elder Stonebark
32913,33392, -- Elder Ironbranch
33350,            -- Mimiron
32865,33147, -- Thorim
33271,33449, -- General Vezax
32871,33070, -- Algalon the Observer
33288,33955); -- Yogg-Saron
