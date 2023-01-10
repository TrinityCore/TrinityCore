DELETE FROM `quest_greeting` WHERE (`Type`=0 AND `ID` IN (194772,191895,186184,186779,186688,186305,186228,196566,196416,190180,196812,186649,186618,191810,196499,186640,196432));
INSERT INTO `quest_greeting` (`ID`, `Type`, `GreetEmoteType`, `GreetEmoteDelay`, `Greeting`, `VerifiedBuild`) VALUES
(194772, 0, 0, 0, 'These giants might be the dragons\' ancient enemies... but they don\'t stand a chance against the likes of me.', 46801), -- 194772
(191895, 0, 1, 0, 'We are so close to saving them all!', 46801), -- 191895
(186184, 0, 0, 0, 'We\'ll need to hurry if we\'re going to fix this place and repower the oathstone.', 46801), -- 186184
(186779, 0, 0, 0, 'We\'re close to finishing this, $n. Just a little longer before Kalecgos and I can aid you.', 46801), -- 186779
(186688, 0, 0, 0, 'The sheer power of the primalists to carve through a mountain like this... they must be stopped at all costs.', 46801), -- 186688
(186305, 0, 0, 0, 'It\'s time we put a stop to the primalists and their insane plans.', 46801), -- 186305
(186228, 0, 1, 0, 'We must learn more about these gnolls, and what they\'re plotting.', 46801), -- 186228
(196566, 0, 1, 0, 'The rebels who harm innocents cannot be redeemed.', 46924), -- 196566
(196416, 0, 1, 0, 'To think that the rebel hideaway was right under our noses...', 46924), -- 196416
(190180, 0, 0, 0, 'Who are the primalists and what do they want? I don\'t care, they killed my friends and that makes them my sworn enemy.', 46801), -- 190180
(196812, 0, 0, 0, 'You know what you need to do.', 46924), -- 196812
(186649, 0, 1, 0, 'We have to put an end to the gorloc menace before we can return back to camp.', 46924), -- 186649
(186618, 0, 0, 0, '<Hanu is panting heavily, having exerted herself. She is clearly injured again.>', 46801), -- 186618
(191810, 0, 1, 0, 'We\'ll need to be at least as cunning as these gnolls if we want to recover what they stole.', 46801), -- 191810
(196499, 0, 0, 0, 'Happy to help with whatever you need.', 47067), -- 196499
(186640, 0, 0, 0, 'These giants might be the dragons\' ancient enemies... but they don\'t stand a chance against the likes of me.', 46801), -- 186640
(196432, 0, 1, 0, 'It\'s alarming that the rebels were so easily swayed by the Primalists into harming their own kin.', 46924); -- 196432


DELETE FROM `quest_details` WHERE `ID` IN (66596 /*Whispers on the Winds*/, 72240 /*The Obsidian Warders*/, 66589 /*Expeditionary Coordination*/, 65436 /*The Dragon Isles Await*/, 66438 /*Lofty Goals*/, 66436 /*Unearthed Troublemakers*/, 66831 /*Home Is Where the Frogs Are*/, 66830 /*Hornswoggled!*/, 69896 /*Disastrous Detour*/, 66828 /*Huddle at the Hollow*/, 66735 /*Just a Trim*/, 66119 /*Ruby Life Pools: Primalist Invasion*/, 66121 /*Egg Evac*/, 66116 /*The Primary Threat*/, 65791 /*Life-Binder on Duty*/, 65793 /*Black Wagon Flight*/, 66057 /*Restoring the Faith*/, 66354 /*The Spark*/, 66055 /*A Shattered Past*/, 66044 /*Taking the Walls*/, 65939 /*The Courage of One's Convictions*/, 65957 /*No Time for Heroes*/, 65956 /*Talon Strike*/, 66078 /*Sharp Practice*/, 72241 /*Lessons From Our Past*/, 66079 /*Wrathion Awaits*/, 66124 /*Exeunt, Triumphant*/, 66123 /*Cut Off the Head*/, 70136 /*Haven't Got Time For the Pain*/, 66080 /*Temporal Difficulties*/, 66320 /*The Flow of Time*/, 72406 /*Orientation: Valdrakken*/, 66252 /*Reporting In*/, 66251 /*Fire Fighter*/, 66249 /*Clear the Sky*/, 66248 /*Tying Things Together*/, 66247 /*Slightly Used Weapons*/, 66245 /*Remember the Fallen*/, 66169 /*Vengeance, Served Hot*/, 66246 /*The Fog of Battle*/, 66167 /*Southern Exposure*/, 66163 /*Nowhere to Hide*/, 70633 /*Fueling the Engine*/, 70182 /*The Sweet Taste of Victory*/, 70181 /*First Challenge of Tyr: Finesse*/, 72435 /*Orientation: Iskaara*/, 72192 /*Halls of Infusion: Entropy to Order*/, 71179 /*Look to the Overlook*/, 71024 /*Chaos and Commotion*/, 71232 /*Renown of the Dragon Isles*/, 66221 /*Moving On*/, 66660 /*On Your Mark... Get Set...*/, 66035 /*Murloc Motes*/, 72519 /*Temporal Two-ning*/, 66033 /*To the... Past?*/, 66031 /*Making Time*/, 66030 /*Resistance Isn't Futile*/, 66029 /*Temporal Tuning*/, 70040 /*Tumbling Through Time*/, 65947 /*Time-Locked Timewalkers*/, 71210 /*To Dragonbane Keep!*/, 65935 /*Catching Up to Chromie*/, 66085 /*If We Could Turn Back Time*/, 66083 /*Feels Like the First Time*/, 67772 /*The Trouble with Taivan*/, 66864 /*Relic Recovery: Brackenhide Hollow*/, 66940 /*Elixir Experiment*/, 70531 /*-Unknown-*/, 69946 /*The Master of Their Craft*/, 70938 /*Community Feasts*/, 72448 /*Securing Our Legacy*/, 70750 /*Aiding the Accord*/, 65916 /*We Don't Negotiate with Primalists*/, 65921 /*Refti Retribution*/, 65918 /*Preventative Maintenance*/, 65913 /*Wotcher, Watcher?*/, 72067 /*Relaxation Time!*/, 71229 /*Call of the Plains*/, 70550 /*Welcome to the Assembly*/, 66781 /*A Matter of Taste*/, 71230 /*Tuskarr Fishing Gear*/, 29506 /*A Fizzy Fusion*/, 29510 /*Putting Trash to Good Use*/, 66152 /*Nowhere to Go*/, 66151 /*His Stone Heart*/, 66148 /*Former Furbolg Family*/, 66150 /*Rescuing Radza*/, 66429 /*I Will Remember*/, 66423 /*Worries and Validations*/, 66353 /*R.A.D. Anomalies*/, 66141 /*Broken Traditions, Broken Bodies*/, 70338 /*They Took the Kits*/, 69862 /*Save a Slyvern*/, 68644 /*Sugar, Spice, and Everything Nice*/, 68643 /*Vitamins and Minerals*/, 68642 /*Needles to Say*/, 66964 /*Artifacts in the Wrong Hands*/, 71235 /*Field Mages*/, 71015 /*All Brawn, No Brains*/, 71014 /*A Far Furbolg Friend*/, 66715 /*The Extraction*/, 66708 /*Riders in the Snow*/, 70970 /*Good Intentions*/, 70946 /*No One May Wield It*/, 70937 /*What Valthrux Once Was*/, 70859 /*What the Guardian Beholds*/, 70856 /*Kill it with Fire*/, 67111 /*The Ailing Apprentice*/, 71017 /*Naluki's Letter*/, 66840 /*Water Safety*/, 66839 /*It's Brew Time!*/, 67177 /*WANTED: Gorger*/, 67174 /*Arcane Detection*/, 66676 /*Sneaking In*/, 65711 /*Stealing Its Thunder*/, 65761 /*More Adventure Than Expected*/, 65770 /*A Promise Is A Promise*/, 65907 /*Favorite Fruit*/, 66684 /*Storm Chasing*/, 66689 /*More Than A Rock*/, 66680 /*Counting Sheep*/, 66681 /*Tempests Abound*/, 66006 /*Return to Roscha*/, 65952 /*A Chief of Legends*/, 65953 /*The Ora-cull*/, 71231 /*Call of the Hunt*/, 67921 /*The Hunting Hound*/, 70444 /*The Fields of Ferocity*/, 72291 /*Story of a Memorable Victory*/, 66595 /*Dormant Discovery*/, 66308 /*Feeding the Fire*/, 69919 /*A Craft in Need*/, 66897 /*Fuel for the Forge*/, 70723 /*Shattering the Earth Primalists*/, 71242 /*Supporting the Storm Researchers*/, 66513 /*Ground Leave*/, 65098 /*The Consequence of Courage*/, 65097 /*Run!*/, 65052 /*The Ebon Scales*/, 65046 /*The Primalists*/, 65049 /*Tangle with the Tarasek*/, 65050 /*Conjured Army*/, 65045 /*Stormsunder Crater*/, 65075 /*The Healing Wings*/, 66324 /*Never Forgotten*/, 65073 /*A Toxic Problem*/, 65036 /*Train Like We Fight*/, 64873 /*Stretch Your Wings*/, 65615 /*Arcane Intrusion*/, 64871 /*The Dragon at the Door*/, 64865 /*Gear Up*/, 64864 /*Awaken, Dracthyr*/, 67700 /*To the Dragon Isles!*/, 65996 /*Veteran Reinforcements*/, 65993 /*Killjoy*/, 66196 /*A Quack For Help*/, 66106 /*Don't Be So Shellfish*/, 66104 /*Forensic Ecology*/, 66107 /*Wildlife Rescue*/, 66105 /*A Scalpel of a Solution*/, 65991 /*Time for a Reckoning*/, 65990 /*Deliver Whelps From Evil*/, 65989 /*Invader Djaradin*/, 65760 /*Reporting for Duty*/, 69912 /*My First Real Emergency!*/, 66112 /*Always Be Crafting*/, 69965 /*Quality Assurance*/, 70135 /*Encroaching Elementals*/, 67053 /*Give Peace a Chance*/, 70124 /*Practice Materials*/, 67137 /*Professionally Equipped*/, 67143 /*To Give One's Heart*/, 70994 /*Drainage Solutions*/, 65864 /*Catch the Caravan*/, 69904 /*Suspiciously Quiet*/, 66699 /*Ask the Locals*/, 65855 /*Aiding Azure Span*/, 65751 /*Platform Adjustments*/, 65689 /*The Many Images of Kalecgos*/, 65688 /*Meeting Kalecgos*/, 67036 /*Wrath of the Kirin Tor*/, 67035 /*Preservation of Knowledge*/, 66340 /*Into the Azure*/, 66336 /*The Isle of Emerald*/, 66337 /*Stormbreaker*/, 66335 /*Deconstruct Additional Pylons*/, 66784 /*Starve the Storm*/, 66333 /*Justice for Solethus*/, 70220 /*Shady Sanctuary*/, 66259 /*A Storm of Ill Tidings*/, 66258 /*Oh No, Ohn'ahra!*/, 66256 /*Eagle-itarian*/, 66257 /*Fowl Sorcery*/, 70195 /*Taken By Storm*/, 66225 /*Toting Totems*/, 66224 /*Mystic Mystery*/, 66254 /*Pessimistic Mystic*/, 70229 /*Boku the Mystic*/, 66023 /*Trucebreakers*/, 66021 /*Unwelcome Outsider*/, 72429 /*Orientation: Maruukai*/, 66016 /*Clan Teerai*/, 65805 /*Connection to Ohn'ahra*/, 70185 /*Mysterious Beast*/, 65804 /*For Food and Rivalry*/, 65803 /*Toward the City*/, 65802 /*Supplies for the Journey*/, 65801 /*Making Introductions*/, 65783 /*Welcome at Our Fire*/, 72783 /*Crafting Orders*/, 72397 /*Orientation: Dragonscale Basecamp*/, 70845 /*In Tyr's Footsteps*/, 70180 /*Jump-Start? Jump-Starting!*/, 72773 /*Learning Ingenuity*/, 72585 /*Open Orientation*/, 66040 /*Back to the Future*/, 66039 /*Chromie Time*/, 66038 /*Race Through Time!*/, 66037 /*Back to Reality*/, 70373 /*Deathwingurlugull!*/, 66036 /*Mugurlglrlgl!*/, 66032 /*Return to the Present*/, 66028 /*To the Future!*/, 65962 /*The Never-Final Countdown*/, 65938 /*The Once and Future Team*/, 66646 /*Quelling Causalities*/, 65948 /*Cracks in Time*/, 66087 /*Closing Time*/, 66084 /*Times Like These*/, 66081 /*Time is Running Out*/, 66082 /*Time in a Bottle*/, 71155 /*The Azure Vaults*/, 66868 /*Preserving the Past: Legacy of Tyr*/, 66884 /*Fireproof Gear*/, 70126 /*A Finishing Touch*/, 67298 /*The Wonders of the World*/, 67295 /*That's My Specialty*/, 66558 /*Rowie*/, 66212 /*Fishing: Aileron Seamoth*/, 66217 /*WANTED: Krojek the Shoreprowler*/, 66218 /*Scampering Scamps*/, 70732 /*A Practice Bout*/, 69979 /*A Worthy Hunt*/, 66213 /*The Weave of a Tale*/, 71234 /*Nook News*/, 70941 /*Fishing Holes*/, 69900 /*Identifying the Source*/, 69899 /*Secret Research*/, 66524 /*Amateur Protography*/, 70995 /*Wanted: Fenistrasza's Skull*/, 66003 /*Rings To Bind Them*/, 70240 /*Pain Management*/, 70239 /*Untold Regrets*/, 65949 /*The Sole Mender*/, 65796 /*The Best Defense...*/, 65792 /*Teeth for a Tooth*/, 66698 /*Counting Argali*/, 69934 /*Bleeding Hearts*/, 69933 /*Curiosity's Price*/, 66467 /*Art Imitates Life*/, 66456 /*A Poisonous Palette*/, 71219 /*The Wayward Waywatcher*/, 70876 /*Fracture the Foci*/, 70850 /*Maldra's in Hot Water*/, 70838 /*Rebels With a Cause*/, 70837 /*Follow the Clues*/, 68641 /*Mossing the Mark*/, 68639 /*Prowling Polar Predators*/, 67299 /*Drakes be Gone*/, 71016 /*Grimtusk's Sister*/, 71013 /*No Vengeance on an Empty Stomach*/, 66730 /*True Survivors*/, 67050 /*Frostbite: Causes and Symptoms*/, 66703 /*Snowball Effect*/, 66709 /*Field Medic 101*/, 66489 /*Setting the Defense*/, 66493 /*Send It!*/, 66523 /*Tending the Forge*/, 72524 /*Basic Climbing Gear*/, 65833 /*Primalist Tampering*/, 65832 /*Dwarven Antifreeze*/, 65758 /*Grungir the Explorer*/, 65769 /*Icy Webs*/, 65750 /*Eight-Legged Menace*/, 66957 /*A Shadow In The Ice*/, 65901 /*Sneaking Out*/, 69915 /*Targeted Ads*/, 65836 /*Show of Storm*/, 66683 /*Last Resort Analysis*/, 65955 /*A Centaur's Best Friend*/, 65954 /*Release the Hounds*/, 66860 /*Relic Recovery: Legacy of Tyr*/, 66874 /*Preserving the Past: Halls of Infusion*/, 66019 /*Honoring Our Ancestors*/, 65806 /*Maruukai*/, 66848 /*Omens on the Wind*/, 65940 /*By Broken Road*/, 66005 /*Medallion of a Fallen Friend*/, 65951 /*Sole Supplier*/, 65779 /*Into the Plains*/, 72728 /*The World Awaits*/, 66847 /*Vault of the Incarnates: Fury of the Storm-Eater*/, 67073 /*Red Dawn*/, 66675 /*Aspect Power*/, 70437 /*To Tyrhold*/, 66875 /*Preserving the Past: Algeth'ar Academy*/, 72172 /*Essence, Shards, and Chromatic Dust*/, 70532 /*Aiding the Raiding*/, 72648 /*Sparks of Life: The Azure Span*/, 71018 /*Vault of the Incarnates: Break a Few Eggs*/, 60545 /*Shadowlands: A Chilling Summons*/, 65101 /*An Iconic, Draconic Look*/, 66577 /*Aspectral Invitation*/, 65286 /*Draconic Connections*/, 65100 /*Final Orders*/, 65087 /*The Prize Inside*/, 65084 /*The Froststone Vault*/, 65701 /*Preservation or Devastation*/, 65057 /*Rally to Emberthal*/, 65307 /*Mercy First*/, 65074 /*Easy Prey*/, 65063 /*Into the Hive*/, 65060 /*Caldera of the Menders*/, 64872 /*The Fire Within*/, 64866 /*Into the Cauldron*/, 64863 /*Arcane Guardians*/, 66458 /*Legacy of Tyr: Secrets of the Past*/, 66998 /*Fighting Fire with... Water*/, 65995 /*The Obsidian Citadel*/, 65992 /*Blacktalon Intel*/, 66108 /*A Sledgehammer of a Solution*/, 72122 /*Erstwhile Ecologists*/, 69914 /*The Djaradin Have Awoken*/, 69911 /*Excuse the Mess*/, 66101 /*From Such Great Heights*/, 72709 /*Funding a Treasure Hunt*/, 70125 /*Where is Wrathion?*/, 72708 /*Dragon Isles Supplies*/, 70123 /*Primal Pests*/, 70122 /*Explorers in Peril*/, 66931 /*Who Brought the Ruckus?*/, 67100 /*A Gift for Miguel*/, 70061 /*Training Wings*/, 68799 /*Return to the Ruby Lifeshrine*/, 68796 /*The Skytop Observatory*/, 65133 /*How to Use Momentum with Your Dragon*/, 65120 /*How to Dive with Your Dragon*/, 70132 /*Stay a While*/, 70058 /*Friend on the Mend*/, 70351 /*Garden Party*/, 66997 /*Nursery Direction*/, 66825 /*A Ruby Lifecalling*/, 68795 /*Dragonriding*/, 66115 /*The Mandate of the Red*/, 66114 /*For the Benefit of the Queen*/, 70179 /*A Two for One Deal*/, 65999 /*Red in Tooth and Claw*/, 65998 /*Future of the Flights*/, 65997 /*Chasing Sendrax*/, 66439 /*Rapid Fire Plans*/, 66441 /*Distilled Effort*/, 66437 /*A Key Element*/, 66435 /*Site Salvage*/, 66827 /*Flowers of our Labor*/, 70134 /*Memories*/, 66734 /*Leave Bee Alone*/, 66122 /*Proto-Fight*/, 66118 /*Basalt Assault*/, 65795 /*Next Steppes*/, 65794 /*A Charge of Care*/, 66788 /*Egg-cited for the Future*/, 66785 /*The Last Eggtender*/, 66779 /*Heir Apparent*/, 66780 /*Claimant to the Throne*/, 66056 /*Forging a New Future*/, 66049 /*Obsidian Oathstone*/, 66048 /*Best Plans and Intentions*/, 65854 /*Reclaiming the Oathstone*/, 65752 /*Arcane Annoyances*/, 65852 /*Straight to the Top*/, 65709 /*Arcane Pruning*/, 65702 /*Driven Mad*/, 67033 /*Assemble the Defenses*/, 66228 /*Camp Antonidas*/, 65686 /*To the Azure Span*/, 66783 /*Renewal of Vows*/, 66331 /*The Primalist Front*/, 66344 /*With the Wind at Our Backs*/, 66328 /*Green Dragon Down*/, 66329 /*Blowing of the Horn*/, 70244 /*Nokhud Can Come of This*/, 66327 /*Chasing the Wind*/, 66242 /*Weather Control*/, 66236 /*Catching Wind*/, 66222 /*The Calm Before the Storm*/, 66201 /*Hooves of War*/, 66025 /*The Nokhud Threat*/, 66024 /*Covering Their Tails*/, 66022 /*The Khanam Matra*/, 66948 /*The Emissary's Arrival*/, 66969 /*Clans of the Plains*/, 66020 /*Omens and Incense*/, 66018 /*Clan Nokhud*/, 66017 /*Clan Ohn'ir*/, 70174 /*The Shikaar*/, 65958 /*Primal Power*/, 65944 /*Lava Burst*/, 65887 /*To the Mountain*/, 65886 /*To Rhonin's Shield*/, 66027 /*Calling the Blue Dragons*/, 65847 /*Realignment*/, 65845 /*Echoes of the Fallen*/, 65844 /*Cut Out the Rot*/, 66239 /*Spreading Decay*/, 65872 /*Ill Gnolls with Ill Intent*/, 65870 /*Supplies!*/, 65866 /*Snap the Traps*/, 66470 /*The Forward Push*/, 66468 /*What Once Was Ours*/, 65920 /*For the Ward!*/, 70139 /*Where There's a Ward, There's a Way*/, 70883 /*A Hand in Cultivation*/, 72246 /*Serene Dreams*/, 70129 /*Toejam the Terrible*/, 66223 /*Can We Keep It?*/, 70722 /*What Lubbins Needs*/, 70438 /*Flying Fish*/, 65789 /*Where Rivers Sleep*/, 72584 /*Setting Your Very Own Net*/, 70871 /*Iskaaran Fishing Net*/, 65778 /*Screechflight Potluck*/, 65371 /*A Nest of Our Own*/, 65287 /*Separating the Yolk*/, 65313 /*A Roc-ing Appetite*/, 69932 /*Every Life Counts*/, 66465 /*Cache and Release*/, 66457 /*Ending the Blue Period*/, 66230 /*A Sketchy Request*/, 66100 /*Supplying in Weight*/, 70879 /*Report on the Rebels*/, 70875 /*Worst of the Worst*/, 70878 /*Ring of Fire*/, 70874 /*To Breach a Fire Wall*/, 70873 /*Chasing Waterfalls*/, 70843 /*Ruin the Runestones*/, 70842 /*Detonation Locations*/, 70627 /*What of the Winterpelt Clan?*/, 66149 /*Elemental Influence*/, 66428 /*Friendship For Granted*/, 66427 /*A Looming Menace*/, 66426 /*Running Out of Time*/, 66425 /*Arcane Overload*/, 66422 /*The Expedition Continues!*/, 66352 /*What the Enemy Knows*/, 66391 /*To the Ruins!*/, 66555 /*Bear With Me*/, 66553 /*Hollow Up*/, 66554 /*Aggressive Self-Defence*/, 66622 /*Wayward Tools*/, 71012 /*Varsek Recruited*/, 71009 /*Elementary, My Dear Drakonid*/, 66846 /*The Heart of the Deck*/, 69855 /*A Climber's Calling*/, 66845 /*Legendary Foil*/, 66841 /*A Shard of the Past*/, 66838 /*It's Cold Up Here*/, 66837 /*Nothing for Breakfast*/, 66844 /*The Great Shokhari*/, 65421 /*Climb Every Mountain*/, 66351 /*Smoke Over the Mountain*/, 67175 /*How To Stop An Exploding Toy Boat*/, 66227 /*Some Good Fishing*/, 70739 /*Bloodlines, Sweets, and Teerai*/, 70501 /*License to Hunt*/, 70156 /*An Ancient Awakening*/, 70154 /*A Gateway to Somewhere*/, 66582 /*Power Procurement*/, 70215 /*Curiosity is Key*/, 71008 /*Wanted: Stoneheart's Stone Heart*/, 70702 /*Continued Waygate Exploration*/, 69869 /*A Cataloger's Paradise*/, 71178 /*Waygate: Shady Sanctuary*/, 71162 /*Waygate: Algeth'era*/, 71157 /*Waygate: Skytop Observatory*/, 72525 /*Basic Cataloging Gear*/, 66445 /*Honor Our Fallen*/, 69918 /*Shaking Our Foundations*/, 66326 /*The Tools of One's Trade*/, 68798 /*Dragon Glyphs and You*/, 68797 /*A New Set of Horns*/, 65118 /*How to Glide with Your Dragon*/, 67564 /*Artisan's Courier*/, 66879 /*Hornstrider Havoc*/, 66001 /*A Last Hope*/, 66000 /*Library of Alexstrasza*/, 66244 /*To Valdrakken*/, 66015 /*The Blue Dragon Oathstone*/, 70041 /*The Storm-Eater's Fury*/, 66009 /*In Defense of Vakthros*/, 66007 /*Free Air*/, 65977 /*Kirin Tor Recovery*/, 66647 /*Elemental Unfocus*/, 65943 /*Primal Offensive*/, 65911 /*Azure Alignment*/, 65850 /*The Cycle of the Sea*/, 66211 /*Brackenhide Hollow: To the Source*/, 66210 /*Gather the Family*/, 65849 /*To Iskaara*/, 65848 /*Tome-ward Bound*/, 65846 /*Ley Litter*/, 65838 /*Breaching the Brackenhide*/, 66026 /*Urgent Action Required*/, 65869 /*Another Ambush*/, 65871 /*Gnoll Way Out*/, 65873 /*Leader of the Shadepaw Pack*/, 65867 /*Howling in the Big Tree Hills*/, 65868 /*Those Aren't for Chewing*/, 66250 /*Where's The Chief?*/, 66166 /*Eyes and Ears*/, 66159 /*A Message Most Dire*/, 66633 /*Make a Statement*/, 66103 /*Eager to Please*/, 69898 /*Scientific Meat-thod*/, 69897 /*Behavior Analysis "Homework"*/, 71001 /*Wanted: Earthbound Primordial Core*/, 66368 /*Island In A Storm*/, 66369 /*The Earthen Ward*/, 66737 /*A Better Start*/, 70029 /*Artisan's Supply: Runed Serevite Rods*/, 70450 /*Otter Devastation*/, 66299 /*The Awaited Egg-splosion*/, 65374 /*It's Plucking Time*/, 65475 /*Rolling in the Screech*/, 65490 /*Explosive Excrement*/, 65373 /*Plucking Parts*/, 65267 /*Smash 'Em to Feathereens*/, 66071 /*Flying Rocs*/, 66556 /*Ice Cave Ya Got There*/, 70931 /*Whispered Fragments*/, 70858 /*Back into the Action*/, 67724 /*The Fending Flames*/, 66488 /*WANTED: Frigellus*/, 66671 /*Path to Nowhere*/, 66503 /*For The Love of Others*/, 66500 /*Ways of Seeing*/, 66843 /*Out of Lukh*/, 65834 /*Kill the Queen*/, 67047 /*Warm Away These Shivers*/, 70930 /*All Tea, No Shadeleaf*/, 71238 /*The Ruby Feast!*/, 72456 /*Tomes Of Trust*/, 72135 /*Neltharus: Secrets Within*/, 70533 /*Draught, Oiled Again*/, 72175 /*A Scept-acular Time*/, 72423 /*Weathering the Storm*/, 66972 /*Old Stonetusk*/, 66598 /*Nightborne Know-How*/, 66597 /*This Old Stone*/, 71011 /*Wanted: Torrential Lily*/, 65950 /*Thieving Gorlocs*/, 65780 /*Proving Oneself*/, 70589 /*Blacksmithing Services Requested*/, 70235 /*Repair Bill*/, 72354 /*The Great Vault*/, 70341 /*Well Earned Victory*/, 70376 /*Second Challenge of Tyr: Might*/, 70339 /*In Tyr's Footsteps: The Ohn'ahran Plains*/, 72427 /*Animated Infusion*/, 72686 /*Storm Surge*/, 72261 /*More Than a Prison?*/, 71138 /*Waygate: Rusza'thar Reach*/, 69984 /*Gold-Banded Dragon Tooth*/, 70848 /*Forgotten Dragon Crest*/, 70847 /*Ancient Obsidian Charm*/, 65842 /*Disarming Behavior*/);
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(66596, 1, 0, 0, 0, 0, 0, 0, 0, 46741), -- Whispers on the Winds
(72240, 1, 1, 0, 0, 0, 1000, 0, 0, 46741), -- The Obsidian Warders
(66589, 25, 1, 0, 0, 0, 2000, 0, 0, 46741), -- Expeditionary Coordination
(65436, 1, 0, 0, 0, 0, 0, 0, 0, 46741), -- The Dragon Isles Await
(66438, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Lofty Goals
(66436, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Unearthed Troublemakers
(66831, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Home Is Where the Frogs Are
(66830, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Hornswoggled!
(69896, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Disastrous Detour
(66828, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Huddle at the Hollow
(66735, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Just a Trim
(66119, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Ruby Life Pools: Primalist Invasion
(66121, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Egg Evac
(66116, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- The Primary Threat
(65791, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Life-Binder on Duty
(65793, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Black Wagon Flight
(66057, 1, 1, 1, 0, 0, 0, 0, 0, 46801), -- Restoring the Faith
(66354, 1, 1, 1, 0, 0, 0, 0, 0, 46801), -- The Spark
(66055, 669, 669, 669, 0, 0, 0, 0, 0, 46801), -- A Shattered Past
(66044, 457, 457, 457, 0, 0, 0, 0, 0, 46801), -- Taking the Walls
(65939, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- The Courage of One's Convictions
(65957, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- No Time for Heroes
(65956, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Talon Strike
(66078, 1, 5, 25, 0, 0, 0, 0, 0, 46801), -- Sharp Practice
(72241, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Lessons From Our Past
(66079, 1, 1, 1, 0, 0, 0, 0, 0, 46801), -- Wrathion Awaits
(66124, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Exeunt, Triumphant
(66123, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Cut Off the Head
(70136, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Haven't Got Time For the Pain
(66080, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Temporal Difficulties
(66320, 1, 1, 5, 0, 0, 0, 0, 0, 46801), -- The Flow of Time
(72406, 1, 6, 0, 0, 0, 0, 0, 0, 46801), -- Orientation: Valdrakken
(66252, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Reporting In
(66251, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Fire Fighter
(66249, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Clear the Sky
(66248, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Tying Things Together
(66247, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Slightly Used Weapons
(66245, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Remember the Fallen
(66169, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Vengeance, Served Hot
(66246, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- The Fog of Battle
(66167, 603, 1, 0, 0, 0, 0, 0, 0, 46801), -- Southern Exposure
(66163, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Nowhere to Hide
(70633, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Fueling the Engine
(70182, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- The Sweet Taste of Victory
(70181, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- First Challenge of Tyr: Finesse
(72435, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Orientation: Iskaara
(72192, 1, 1, 0, 0, 0, 350, 0, 0, 46801), -- Halls of Infusion: Entropy to Order
(71179, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Look to the Overlook
(71024, 1, 1, 0, 0, 0, 500, 0, 0, 46801), -- Chaos and Commotion
(71232, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Renown of the Dragon Isles
(66221, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Moving On
(66660, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- On Your Mark... Get Set...
(66035, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Murloc Motes
(72519, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Temporal Two-ning
(66033, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- To the... Past?
(66031, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Making Time
(66030, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Resistance Isn't Futile
(66029, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Temporal Tuning
(70040, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Tumbling Through Time
(65947, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Time-Locked Timewalkers
(71210, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- To Dragonbane Keep!
(65935, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Catching Up to Chromie
(66085, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- If We Could Turn Back Time
(66083, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Feels Like the First Time
(67772, 2, 0, 0, 0, 0, 0, 0, 0, 46801), -- The Trouble with Taivan
(66864, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- Relic Recovery: Brackenhide Hollow
(66940, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- Elixir Experiment
(70531, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- -Unknown-
(69946, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- The Master of Their Craft
(70938, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- Community Feasts
(72448, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- Securing Our Legacy
(70750, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- Aiding the Accord
(65916, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- We Don't Negotiate with Primalists
(65921, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- Refti Retribution
(65918, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- Preventative Maintenance
(65913, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- Wotcher, Watcher?
(72067, 4, 0, 0, 0, 0, 0, 0, 0, 46879), -- Relaxation Time!
(71229, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- Call of the Plains
(70550, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- Welcome to the Assembly
(66781, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- A Matter of Taste
(71230, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- Tuskarr Fishing Gear
(29506, 1, 1, 0, 0, 0, 0, 0, 0, 46924), -- A Fizzy Fusion
(29510, 1, 1, 1, 0, 0, 0, 0, 0, 46924), -- Putting Trash to Good Use
(66152, 1, 1, 1, 0, 0, 500, 1000, 0, 46924), -- Nowhere to Go
(66151, 1, 1, 1, 0, 0, 500, 1000, 0, 46924), -- His Stone Heart
(66148, 1, 1, 1, 0, 0, 500, 1000, 0, 46924), -- Former Furbolg Family
(66150, 1, 1, 1, 0, 0, 500, 1000, 0, 46924), -- Rescuing Radza
(66429, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- I Will Remember
(66423, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Worries and Validations
(66353, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- R.A.D. Anomalies
(66141, 1, 1, 1, 0, 0, 500, 1000, 0, 46924), -- Broken Traditions, Broken Bodies
(70338, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- They Took the Kits
(69862, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Save a Slyvern
(68644, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Sugar, Spice, and Everything Nice
(68643, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Vitamins and Minerals
(68642, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Needles to Say
(66964, 603, 0, 0, 0, 0, 0, 0, 0, 46924), -- Artifacts in the Wrong Hands
(71235, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Field Mages
(71015, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- All Brawn, No Brains
(71014, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- A Far Furbolg Friend
(66715, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- The Extraction
(66708, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Riders in the Snow
(70970, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Good Intentions
(70946, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- No One May Wield It
(70937, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- What Valthrux Once Was
(70859, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- What the Guardian Beholds
(70856, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Kill it with Fire
(67111, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- The Ailing Apprentice
(71017, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Naluki's Letter
(66840, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Water Safety
(66839, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- It's Brew Time!
(67177, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- WANTED: Gorger
(67174, 1, 1, 0, 0, 0, 0, 0, 0, 46924), -- Arcane Detection
(66676, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Sneaking In
(65711, 603, 0, 0, 0, 0, 0, 0, 0, 46924), -- Stealing Its Thunder
(65761, 669, 0, 0, 0, 0, 0, 0, 0, 46924), -- More Adventure Than Expected
(65770, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- A Promise Is A Promise
(65907, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Favorite Fruit
(66684, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Storm Chasing
(66689, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- More Than A Rock
(66680, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Counting Sheep
(66681, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Tempests Abound
(66006, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Return to Roscha
(65952, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- A Chief of Legends
(65953, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- The Ora-cull
(71231, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Call of the Hunt
(67921, 669, 0, 0, 0, 0, 0, 0, 0, 46924), -- The Hunting Hound
(70444, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- The Fields of Ferocity
(72291, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Story of a Memorable Victory
(66595, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Dormant Discovery
(66308, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Feeding the Fire
(69919, 412, 0, 0, 0, 0, 0, 0, 0, 46924), -- A Craft in Need
(66897, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Fuel for the Forge
(70723, 0, 0, 0, 0, 0, 0, 0, 0, 47067), -- Shattering the Earth Primalists
(71242, 0, 0, 0, 0, 0, 0, 0, 0, 47067), -- Supporting the Storm Researchers
(66513, 1, 0, 0, 0, 0, 0, 0, 0, 46658), -- Ground Leave
(65098, 1, 1, 1, 0, 0, 0, 0, 0, 46658), -- The Consequence of Courage
(65097, 1, 1, 0, 0, 0, 0, 0, 0, 46658), -- Run!
(65052, 1, 5, 0, 0, 0, 0, 0, 0, 46658), -- The Ebon Scales
(65046, 1, 1, 1, 1, 0, 0, 0, 0, 46658), -- The Primalists
(65049, 1, 1, 1, 0, 0, 0, 0, 0, 46658), -- Tangle with the Tarasek
(65050, 1, 1, 1, 0, 0, 0, 0, 0, 46658), -- Conjured Army
(65045, 1, 1, 1, 0, 0, 0, 0, 0, 46658), -- Stormsunder Crater
(65075, 1, 1, 1, 1, 0, 0, 0, 0, 46658), -- The Healing Wings
(66324, 1, 274, 1, 1, 0, 0, 0, 0, 46658), -- Never Forgotten
(65073, 1, 1, 1, 0, 0, 0, 0, 0, 46658), -- A Toxic Problem
(65036, 0, 0, 0, 0, 0, 0, 0, 0, 46658), -- Train Like We Fight
(64873, 1, 1, 6, 1, 0, 0, 0, 0, 46658), -- Stretch Your Wings
(65615, 6, 1, 1, 274, 0, 0, 0, 0, 46658), -- Arcane Intrusion
(64871, 6, 5, 1, 0, 0, 0, 0, 0, 46658), -- The Dragon at the Door
(64865, 1, 1, 5, 0, 0, 0, 0, 0, 46658), -- Gear Up
(64864, 1, 1, 1, 0, 0, 0, 0, 0, 46658), -- Awaken, Dracthyr
(67700, 1, 6, 0, 0, 0, 2000, 0, 0, 46801), -- To the Dragon Isles!
(65996, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Veteran Reinforcements
(65993, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Killjoy
(66196, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- A Quack For Help
(66106, 22, 0, 0, 0, 0, 0, 0, 0, 46801), -- Don't Be So Shellfish
(66104, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Forensic Ecology
(66107, 22, 0, 0, 0, 0, 0, 0, 0, 46801), -- Wildlife Rescue
(66105, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- A Scalpel of a Solution
(65991, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Time for a Reckoning
(65990, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Deliver Whelps From Evil
(65989, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Invader Djaradin
(65760, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Reporting for Duty
(69912, 1, 1, 0, 0, 0, 1000, 0, 0, 46801), -- My First Real Emergency!
(66112, 1, 4, 1, 0, 0, 0, 0, 0, 46801), -- Always Be Crafting
(69965, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Quality Assurance
(70135, 396, 25, 0, 0, 0, 0, 0, 0, 46801), -- Encroaching Elementals
(67053, 669, 25, 0, 0, 0, 0, 0, 0, 46801), -- Give Peace a Chance
(70124, 1, 1, 0, 0, 0, 1000, 0, 0, 46801), -- Practice Materials
(67137, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Professionally Equipped
(67143, 6, 0, 0, 0, 0, 0, 0, 0, 46801), -- To Give One's Heart
(70994, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Drainage Solutions
(65864, 1, 1, 1, 0, 0, 500, 1000, 0, 46801), -- Catch the Caravan
(69904, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Suspiciously Quiet
(66699, 1, 1, 1, 0, 0, 500, 1000, 0, 46801), -- Ask the Locals
(65855, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Aiding Azure Span
(65751, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Platform Adjustments
(65689, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- The Many Images of Kalecgos
(65688, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Meeting Kalecgos
(67036, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Wrath of the Kirin Tor
(67035, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Preservation of Knowledge
(66340, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Into the Azure
(66336, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- The Isle of Emerald
(66337, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Stormbreaker
(66335, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Deconstruct Additional Pylons
(66784, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Starve the Storm
(66333, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Justice for Solethus
(70220, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Shady Sanctuary
(66259, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- A Storm of Ill Tidings
(66258, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Oh No, Ohn'ahra!
(66256, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Eagle-itarian
(66257, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Fowl Sorcery
(70195, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Taken By Storm
(66225, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Toting Totems
(66224, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Mystic Mystery
(66254, 1, 1, 0, 0, 0, 300, 0, 0, 46801), -- Pessimistic Mystic
(70229, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Boku the Mystic
(66023, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Trucebreakers
(66021, 1, 1, 0, 0, 0, 300, 0, 0, 46801), -- Unwelcome Outsider
(72429, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Orientation: Maruukai
(66016, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Clan Teerai
(65805, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Connection to Ohn'ahra
(70185, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Mysterious Beast
(65804, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- For Food and Rivalry
(65803, 1, 1, 0, 0, 0, 300, 0, 0, 46801), -- Toward the City
(65802, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Supplies for the Journey
(65801, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Making Introductions
(65783, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Welcome at Our Fire
(72783, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Crafting Orders
(72397, 1, 6, 0, 0, 0, 0, 0, 0, 46801), -- Orientation: Dragonscale Basecamp
(70845, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- In Tyr's Footsteps
(70180, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Jump-Start? Jump-Starting!
(72773, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Learning Ingenuity
(72585, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Open Orientation
(66040, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Back to the Future
(66039, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Chromie Time
(66038, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Race Through Time!
(66037, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Back to Reality
(70373, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Deathwingurlugull!
(66036, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Mugurlglrlgl!
(66032, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Return to the Present
(66028, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- To the Future!
(65962, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- The Never-Final Countdown
(65938, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- The Once and Future Team
(66646, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Quelling Causalities
(65948, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Cracks in Time
(66087, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Closing Time
(66084, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Times Like These
(66081, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Time is Running Out
(66082, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Time in a Bottle
(71155, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- The Azure Vaults
(66868, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- Preserving the Past: Legacy of Tyr
(66884, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- Fireproof Gear
(70126, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- A Finishing Touch
(67298, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- The Wonders of the World
(67295, 378, 0, 0, 0, 0, 0, 0, 0, 46879), -- That's My Specialty
(66558, 1, 1, 0, 0, 0, 0, 0, 0, 46879), -- Rowie
(66212, 5, 378, 0, 0, 0, 0, 0, 0, 46879), -- Fishing: Aileron Seamoth
(66217, 1, 1, 0, 0, 0, 0, 0, 0, 46879), -- WANTED: Krojek the Shoreprowler
(66218, 1, 1, 0, 0, 0, 0, 0, 0, 46879), -- Scampering Scamps
(70732, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- A Practice Bout
(69979, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- A Worthy Hunt
(66213, 1, 1, 0, 0, 0, 0, 0, 0, 46879), -- The Weave of a Tale
(71234, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- Nook News
(70941, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- Fishing Holes
(69900, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- Identifying the Source
(69899, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- Secret Research
(66524, 1, 1, 0, 0, 0, 0, 0, 0, 46879), -- Amateur Protography
(70995, 1, 0, 0, 0, 0, 0, 0, 0, 46879); -- Wanted: Fenistrasza's Skull

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(66003, 669, 0, 0, 0, 0, 0, 0, 0, 46879), -- Rings To Bind Them
(70240, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- Pain Management
(70239, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- Untold Regrets
(65949, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- The Sole Mender
(65796, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- The Best Defense...
(65792, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- Teeth for a Tooth
(66698, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- Counting Argali
(69934, 1, 273, 0, 0, 0, 3, 0, 0, 46924), -- Bleeding Hearts
(69933, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Curiosity's Price
(66467, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Art Imitates Life
(66456, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- A Poisonous Palette
(71219, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- The Wayward Waywatcher
(70876, 1, 1, 1, 0, 0, 0, 0, 0, 46924), -- Fracture the Foci
(70850, 1, 1, 1, 0, 0, 500, 1000, 0, 46924), -- Maldra's in Hot Water
(70838, 1, 1, 1, 0, 0, 500, 1000, 0, 46924), -- Rebels With a Cause
(70837, 1, 1, 1, 0, 0, 0, 0, 0, 46924), -- Follow the Clues
(68641, 378, 0, 0, 0, 0, 0, 0, 0, 46924), -- Mossing the Mark
(68639, 483, 0, 0, 0, 0, 0, 0, 0, 46924), -- Prowling Polar Predators
(67299, 1, 1, 0, 0, 0, 0, 0, 0, 46924), -- Drakes be Gone
(71016, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Grimtusk's Sister
(71013, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- No Vengeance on an Empty Stomach
(66730, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- True Survivors
(67050, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Frostbite: Causes and Symptoms
(66703, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Snowball Effect
(66709, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Field Medic 101
(66489, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Setting the Defense
(66493, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Send It!
(66523, 11, 0, 0, 0, 0, 0, 0, 0, 46924), -- Tending the Forge
(72524, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Basic Climbing Gear
(65833, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Primalist Tampering
(65832, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Dwarven Antifreeze
(65758, 603, 0, 0, 0, 0, 0, 0, 0, 46924), -- Grungir the Explorer
(65769, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Icy Webs
(65750, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Eight-Legged Menace
(66957, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- A Shadow In The Ice
(65901, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Sneaking Out
(69915, 412, 0, 0, 0, 0, 0, 0, 0, 46924), -- Targeted Ads
(65836, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Show of Storm
(66683, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Last Resort Analysis
(65955, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- A Centaur's Best Friend
(65954, 5, 0, 0, 0, 0, 0, 0, 0, 46924), -- Release the Hounds
(66860, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Relic Recovery: Legacy of Tyr
(66874, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Preserving the Past: Halls of Infusion
(66019, 1, 1, 0, 0, 0, 300, 0, 0, 46924), -- Honoring Our Ancestors
(65806, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Maruukai
(66848, 1, 1, 0, 0, 0, 300, 0, 0, 46924), -- Omens on the Wind
(65940, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- By Broken Road
(66005, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Medallion of a Fallen Friend
(65951, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Sole Supplier
(65779, 1, 1, 0, 0, 0, 300, 0, 0, 46924), -- Into the Plains
(72728, 0, 0, 0, 0, 0, 0, 0, 0, 47067), -- The World Awaits
(66847, 1, 603, 1, 0, 0, 350, 600, 0, 47067), -- Vault of the Incarnates: Fury of the Storm-Eater
(67073, 1, 0, 0, 0, 0, 0, 0, 0, 47067), -- Red Dawn
(66675, 1, 0, 0, 0, 0, 0, 0, 0, 47067), -- Aspect Power
(70437, 1, 1, 0, 0, 0, 0, 0, 0, 47067), -- To Tyrhold
(66875, 1, 0, 0, 0, 0, 0, 0, 0, 47067), -- Preserving the Past: Algeth'ar Academy
(72172, 1, 0, 0, 0, 0, 0, 0, 0, 47067), -- Essence, Shards, and Chromatic Dust
(70532, 1, 0, 0, 0, 0, 0, 0, 0, 47067), -- Aiding the Raiding
(72648, 1, 0, 0, 0, 0, 0, 0, 0, 47067), -- Sparks of Life: The Azure Span
(71018, 0, 0, 0, 0, 0, 0, 0, 0, 47067), -- Vault of the Incarnates: Break a Few Eggs
(60545, 1, 25, 0, 0, 0, 0, 0, 0, 46658), -- Shadowlands: A Chilling Summons
(65101, 25, 1, 1, 1, 0, 0, 0, 0, 46658), -- An Iconic, Draconic Look
(66577, 1, 0, 0, 0, 0, 0, 0, 0, 46658), -- Aspectral Invitation
(65286, 1, 1, 0, 0, 0, 0, 0, 0, 46658), -- Draconic Connections
(65100, 1, 1, 0, 0, 0, 0, 0, 0, 46658), -- Final Orders
(65087, 1, 1, 0, 0, 0, 0, 0, 0, 46658), -- The Prize Inside
(65084, 1, 1, 1, 1, 0, 0, 0, 0, 46658), -- The Froststone Vault
(65701, 1, 1, 1, 1, 0, 0, 0, 0, 46658), -- Preservation or Devastation
(65057, 1, 6, 274, 5, 0, 0, 0, 0, 46658), -- Rally to Emberthal
(65307, 1, 1, 1, 0, 0, 0, 0, 0, 46658), -- Mercy First
(65074, 1, 1, 1, 0, 0, 0, 0, 0, 46658), -- Easy Prey
(65063, 1, 1, 0, 0, 0, 0, 0, 0, 46658), -- Into the Hive
(65060, 1, 1, 1, 0, 0, 0, 0, 0, 46658), -- Caldera of the Menders
(64872, 1, 6, 1, 1, 0, 0, 0, 0, 46658), -- The Fire Within
(64866, 1, 1, 274, 0, 0, 0, 0, 0, 46658), -- Into the Cauldron
(64863, 1, 1, 1, 0, 0, 0, 0, 0, 46658), -- Arcane Guardians
(66458, 1, 0, 0, 0, 0, 0, 0, 0, 46741), -- Legacy of Tyr: Secrets of the Past
(66998, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Fighting Fire with... Water
(65995, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- The Obsidian Citadel
(65992, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Blacktalon Intel
(66108, 273, 0, 0, 0, 0, 0, 0, 0, 46801), -- A Sledgehammer of a Solution
(72122, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Erstwhile Ecologists
(69914, 1, 1, 0, 0, 0, 1000, 0, 0, 46801), -- The Djaradin Have Awoken
(69911, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Excuse the Mess
(66101, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- From Such Great Heights
(72709, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Funding a Treasure Hunt
(70125, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Where is Wrathion?
(72708, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Dragon Isles Supplies
(70123, 1, 1, 0, 0, 0, 1000, 0, 0, 46801), -- Primal Pests
(70122, 1, 1, 0, 0, 0, 1000, 0, 0, 46801), -- Explorers in Peril
(66931, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Who Brought the Ruckus?
(67100, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- A Gift for Miguel
(70061, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Training Wings
(68799, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Return to the Ruby Lifeshrine
(68796, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- The Skytop Observatory
(65133, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- How to Use Momentum with Your Dragon
(65120, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- How to Dive with Your Dragon
(70132, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Stay a While
(70058, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Friend on the Mend
(70351, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Garden Party
(66997, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Nursery Direction
(66825, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- A Ruby Lifecalling
(68795, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Dragonriding
(66115, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- The Mandate of the Red
(66114, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- For the Benefit of the Queen
(70179, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- A Two for One Deal
(65999, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Red in Tooth and Claw
(65998, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Future of the Flights
(65997, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Chasing Sendrax
(66439, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Rapid Fire Plans
(66441, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Distilled Effort
(66437, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- A Key Element
(66435, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Site Salvage
(66827, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Flowers of our Labor
(70134, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Memories
(66734, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Leave Bee Alone
(66122, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Proto-Fight
(66118, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Basalt Assault
(65795, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Next Steppes
(65794, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- A Charge of Care
(66788, 603, 0, 0, 0, 0, 0, 0, 0, 46801), -- Egg-cited for the Future
(66785, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- The Last Eggtender
(66779, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Heir Apparent
(66780, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Claimant to the Throne
(66056, 669, 669, 669, 0, 0, 0, 0, 0, 46801), -- Forging a New Future
(66049, 457, 457, 457, 0, 0, 0, 0, 0, 46801), -- Obsidian Oathstone
(66048, 5, 1, 0, 0, 300, 600, 0, 0, 46801), -- Best Plans and Intentions
(65854, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Reclaiming the Oathstone
(65752, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Arcane Annoyances
(65852, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Straight to the Top
(65709, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Arcane Pruning
(65702, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Driven Mad
(67033, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Assemble the Defenses
(66228, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Camp Antonidas
(65686, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- To the Azure Span
(66783, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Renewal of Vows
(66331, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- The Primalist Front
(66344, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- With the Wind at Our Backs
(66328, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Green Dragon Down
(66329, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Blowing of the Horn
(70244, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Nokhud Can Come of This
(66327, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Chasing the Wind
(66242, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Weather Control
(66236, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Catching Wind
(66222, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- The Calm Before the Storm
(66201, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Hooves of War
(66025, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- The Nokhud Threat
(66024, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Covering Their Tails
(66022, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- The Khanam Matra
(66948, 1, 1, 0, 0, 0, 300, 0, 0, 46801), -- The Emissary's Arrival
(66969, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Clans of the Plains
(66020, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Omens and Incense
(66018, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Clan Nokhud
(66017, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Clan Ohn'ir
(70174, 1, 1, 0, 0, 0, 300, 0, 0, 46801), -- The Shikaar
(65958, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Primal Power
(65944, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Lava Burst
(65887, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- To the Mountain
(65886, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- To Rhonin's Shield
(66027, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Calling the Blue Dragons
(65847, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Realignment
(65845, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Echoes of the Fallen
(65844, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Cut Out the Rot
(66239, 1, 1, 0, 0, 0, 500, 0, 0, 46801), -- Spreading Decay
(65872, 1, 1, 1, 0, 0, 500, 1000, 0, 46801), -- Ill Gnolls with Ill Intent
(65870, 1, 1, 1, 0, 0, 500, 1000, 0, 46801), -- Supplies!
(65866, 1, 1, 1, 0, 0, 500, 1000, 0, 46801), -- Snap the Traps
(66470, 1, 1, 0, 0, 0, 600, 0, 0, 46879), -- The Forward Push
(66468, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- What Once Was Ours
(65920, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- For the Ward!
(70139, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- Where There's a Ward, There's a Way
(70883, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- A Hand in Cultivation
(72246, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- Serene Dreams
(70129, 1, 1, 0, 0, 0, 0, 0, 0, 46879), -- Toejam the Terrible
(66223, 1, 1, 0, 0, 0, 0, 0, 0, 46879), -- Can We Keep It?
(70722, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- What Lubbins Needs
(70438, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- Flying Fish
(65789, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- Where Rivers Sleep
(72584, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- Setting Your Very Own Net
(70871, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- Iskaaran Fishing Net
(65778, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Screechflight Potluck
(65371, 603, 1, 0, 0, 0, 250, 0, 0, 46924), -- A Nest of Our Own
(65287, 603, 1, 0, 0, 0, 250, 0, 0, 46924), -- Separating the Yolk
(65313, 603, 0, 0, 0, 0, 0, 0, 0, 46924), -- A Roc-ing Appetite
(69932, 1, 25, 0, 0, 0, 3, 0, 0, 46924), -- Every Life Counts
(66465, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Cache and Release
(66457, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Ending the Blue Period
(66230, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- A Sketchy Request
(66100, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Supplying in Weight
(70879, 1, 1, 1, 0, 0, 0, 0, 0, 46924), -- Report on the Rebels
(70875, 1, 1, 0, 0, 0, 0, 0, 0, 46924), -- Worst of the Worst
(70878, 1, 1, 1, 0, 0, 0, 0, 0, 46924), -- Ring of Fire
(70874, 1, 1, 1, 0, 0, 0, 0, 0, 46924), -- To Breach a Fire Wall
(70873, 1, 1, 1, 0, 0, 500, 1000, 0, 46924), -- Chasing Waterfalls
(70843, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Ruin the Runestones
(70842, 1, 1, 0, 0, 0, 0, 0, 0, 46924), -- Detonation Locations
(70627, 1, 1, 1, 0, 0, 500, 1000, 0, 46924), -- What of the Winterpelt Clan?
(66149, 1, 1, 0, 0, 0, 500, 0, 0, 46924), -- Elemental Influence
(66428, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Friendship For Granted
(66427, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- A Looming Menace
(66426, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Running Out of Time
(66425, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Arcane Overload
(66422, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- The Expedition Continues!
(66352, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- What the Enemy Knows
(66391, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- To the Ruins!
(66555, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Bear With Me
(66553, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Hollow Up
(66554, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Aggressive Self-Defence
(66622, 18, 0, 0, 0, 0, 0, 0, 0, 46924), -- Wayward Tools
(71012, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Varsek Recruited
(71009, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Elementary, My Dear Drakonid
(66846, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- The Heart of the Deck
(69855, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- A Climber's Calling
(66845, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Legendary Foil
(66841, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- A Shard of the Past
(66838, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- It's Cold Up Here
(66837, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Nothing for Breakfast
(66844, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- The Great Shokhari
(65421, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Climb Every Mountain
(66351, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Smoke Over the Mountain
(67175, 1, 1, 0, 0, 0, 0, 0, 0, 46924), -- How To Stop An Exploding Toy Boat
(66227, 1, 1, 0, 0, 0, 0, 0, 0, 46924), -- Some Good Fishing
(70739, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Bloodlines, Sweets, and Teerai
(70501, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- License to Hunt
(70156, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- An Ancient Awakening
(70154, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- A Gateway to Somewhere
(66582, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Power Procurement
(70215, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Curiosity is Key
(71008, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Wanted: Stoneheart's Stone Heart
(70702, 0, 0, 0, 0, 0, 0, 0, 0, 47067), -- Continued Waygate Exploration
(69869, 1, 0, 0, 0, 0, 0, 0, 0, 47067), -- A Cataloger's Paradise
(71178, 1, 0, 0, 0, 0, 0, 0, 0, 47187), -- Waygate: Shady Sanctuary
(71162, 1, 0, 0, 0, 0, 0, 0, 0, 47187), -- Waygate: Algeth'era
(71157, 1, 0, 0, 0, 0, 0, 0, 0, 47187), -- Waygate: Skytop Observatory
(72525, 1, 0, 0, 0, 0, 0, 0, 0, 47187), -- Basic Cataloging Gear
(66445, 0, 0, 0, 0, 0, 0, 0, 0, 47187), -- Honor Our Fallen
(69918, 0, 0, 0, 0, 0, 0, 0, 0, 47187), -- Shaking Our Foundations
(66326, 0, 0, 0, 0, 0, 0, 0, 0, 47187), -- The Tools of One's Trade
(68798, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Dragon Glyphs and You
(68797, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- A New Set of Horns
(65118, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- How to Glide with Your Dragon
(67564, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Artisan's Courier
(66879, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Hornstrider Havoc
(66001, 1, 25, 0, 0, 0, 0, 0, 0, 46801), -- A Last Hope
(66000, 1, 0, 0, 0, 0, 0, 0, 0, 46801), -- Library of Alexstrasza
(66244, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- To Valdrakken
(66015, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- The Blue Dragon Oathstone
(70041, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- The Storm-Eater's Fury
(66009, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- In Defense of Vakthros
(66007, 1, 1, 0, 0, 0, 0, 0, 0, 46801); -- Free Air

INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(65977, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Kirin Tor Recovery
(66647, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Elemental Unfocus
(65943, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Primal Offensive
(65911, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Azure Alignment
(65850, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- The Cycle of the Sea
(66211, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Brackenhide Hollow: To the Source
(66210, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Gather the Family
(65849, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- To Iskaara
(65848, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Tome-ward Bound
(65846, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Ley Litter
(65838, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Breaching the Brackenhide
(66026, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- Urgent Action Required
(65869, 1, 1, 0, 0, 0, 500, 0, 0, 46801), -- Another Ambush
(65871, 1, 1, 0, 0, 0, 500, 0, 0, 46801), -- Gnoll Way Out
(65873, 1, 1, 1, 0, 0, 500, 1000, 0, 46801), -- Leader of the Shadepaw Pack
(65867, 1, 1, 1, 0, 0, 500, 1000, 0, 46801), -- Howling in the Big Tree Hills
(65868, 1, 1, 1, 0, 0, 500, 1000, 0, 46801), -- Those Aren't for Chewing
(66250, 0, 0, 0, 0, 0, 0, 0, 0, 46801), -- Where's The Chief?
(66166, 1, 1, 5, 0, 0, 0, 0, 0, 46801), -- Eyes and Ears
(66159, 1, 1, 0, 0, 0, 0, 0, 0, 46801), -- A Message Most Dire
(66633, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- Make a Statement
(66103, 1, 1, 1, 0, 0, 0, 0, 0, 46879), -- Eager to Please
(69898, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- Scientific Meat-thod
(69897, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- Behavior Analysis "Homework"
(71001, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- Wanted: Earthbound Primordial Core
(66368, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- Island In A Storm
(66369, 669, 0, 0, 0, 0, 0, 0, 0, 46879), -- The Earthen Ward
(66737, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- A Better Start
(70029, 1, 0, 0, 0, 0, 0, 0, 0, 46879), -- Artisan's Supply: Runed Serevite Rods
(70450, 0, 0, 0, 0, 0, 0, 0, 0, 46879), -- Otter Devastation
(66299, 603, 0, 0, 0, 0, 0, 0, 0, 46924), -- The Awaited Egg-splosion
(65374, 603, 0, 0, 0, 0, 0, 0, 0, 46924), -- It's Plucking Time
(65475, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Rolling in the Screech
(65490, 603, 0, 0, 0, 0, 0, 0, 0, 46924), -- Explosive Excrement
(65373, 603, 0, 0, 0, 0, 0, 0, 0, 46924), -- Plucking Parts
(65267, 1, 25, 0, 0, 0, 250, 0, 0, 46924), -- Smash 'Em to Feathereens
(66071, 603, 0, 0, 0, 0, 0, 0, 0, 46924), -- Flying Rocs
(66556, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Ice Cave Ya Got There
(70931, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Whispered Fragments
(70858, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Back into the Action
(67724, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- The Fending Flames
(66488, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- WANTED: Frigellus
(66671, 1, 1, 1, 0, 0, 500, 1000, 0, 46924), -- Path to Nowhere
(66503, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- For The Love of Others
(66500, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Ways of Seeing
(66843, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Out of Lukh
(65834, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Kill the Queen
(67047, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Warm Away These Shivers
(70930, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- All Tea, No Shadeleaf
(71238, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- The Ruby Feast!
(72456, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Tomes Of Trust
(72135, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Neltharus: Secrets Within
(70533, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Draught, Oiled Again
(72175, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- A Scept-acular Time
(72423, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Weathering the Storm
(66972, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Old Stonetusk
(66598, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Nightborne Know-How
(66597, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- This Old Stone
(71011, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Wanted: Torrential Lily
(65950, 35, 0, 0, 0, 0, 0, 0, 0, 46924), -- Thieving Gorlocs
(65780, 1, 1, 0, 0, 0, 0, 0, 0, 46924), -- Proving Oneself
(70589, 1, 0, 0, 0, 0, 0, 0, 0, 46924), -- Blacksmithing Services Requested
(70235, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Repair Bill
(72354, 0, 0, 0, 0, 0, 0, 0, 0, 47067), -- The Great Vault
(70341, 0, 0, 0, 0, 0, 0, 0, 0, 47067), -- Well Earned Victory
(70376, 0, 0, 0, 0, 0, 0, 0, 0, 47067), -- Second Challenge of Tyr: Might
(70339, 0, 0, 0, 0, 0, 0, 0, 0, 47067), -- In Tyr's Footsteps: The Ohn'ahran Plains
(72427, 0, 0, 0, 0, 0, 0, 0, 0, 47067), -- Animated Infusion
(72686, 0, 0, 0, 0, 0, 0, 0, 0, 47067), -- Storm Surge
(72261, 0, 0, 0, 0, 0, 0, 0, 0, 47067), -- More Than a Prison?
(71138, 1, 0, 0, 0, 0, 0, 0, 0, 47187), -- Waygate: Rusza'thar Reach
(69984, 0, 0, 0, 0, 0, 0, 0, 0, 47187), -- Gold-Banded Dragon Tooth
(70848, 0, 0, 0, 0, 0, 0, 0, 0, 47187), -- Forgotten Dragon Crest
(70847, 0, 0, 0, 0, 0, 0, 0, 0, 47187), -- Ancient Obsidian Charm
(65842, 0, 0, 0, 0, 0, 0, 0, 0, 47187); -- Disarming Behavior

UPDATE `quest_details` SET `VerifiedBuild`=46658 WHERE `ID`=32675;
