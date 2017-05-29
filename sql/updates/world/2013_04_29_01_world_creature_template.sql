UPDATE creature_template SET mechanic_immune_mask=mechanic_immune_mask
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
WHERE entry IN
(28859,31734, -- Malygos
39863,39864,39944,39945,40142,40143,40144,40145, -- Halion
39746,39805, -- General Zarithrian
39747,39823, -- Saviana Ragefire
39751,39899,39920,39922, -- Baltharus the Warborn
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
33350, -- Mimiron
32865,33147, -- Thorim
33271,33449, -- General Vezax
32871,33070, -- Algalon the Observer
33288,33955, -- Yogg-Saron
31134,31506, -- Cyanigosa
32273,32313, -- Infinite Corruptor
30258,31463, -- Amanitar
29932, -- Eck the Ferocious
29573,31367, -- Drakkari Elemental
29316,31510, -- Moragg
29315,31507, -- Erekem
29314,31512, -- Zuramat the Obliterator
29313,31508, -- Ichoron
29312,31509, -- Lavanthor
29311,31464, -- Herald Volazj
29310,31465, -- Jedoga Shadowseeker
29308,31469, -- Prince Taldaram
29307,31365, -- Drakkari Colossus
29306,31368, -- Gal'darah
29305,30530, -- Moorabi
29304,31370, -- Slad'ran
29266,31511, -- Xevozz
28923,31538, -- Loken
28921,31611, -- Hadronox
28587,31536, -- Volkhan
28586,31533, -- General Bjarngrim
28546,31537, -- Ionar
27978,31386, -- Sjonnir The Ironshaper
27977,31381, -- Krystallus
27975,31384, -- Maiden of Grief
27656,31561, -- Ley-Guardian Eregos
27655,31560, -- Mage-Lord Urom
27654,31558, -- Drakos the Interrogator
27447,31559, -- Varos Cloudstrider
27390,31680, -- Skarvald the Constructor
27389,31657, -- Dalronn the Controller
26687,30774, -- Gortok Palehoof
26533,31217, -- Mal'Ganis
26532,31215, -- Chrono-Lord Epoch
26530,31212, -- Salramm the Fleshcrafter
27483,31349); -- King Dred
