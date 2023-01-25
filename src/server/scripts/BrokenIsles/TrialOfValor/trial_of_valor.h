#ifndef TrialOfValorH_
#define TrialOfValorH_

namespace Data
{
    enum BossIDs
    {
        OdynID = 0,
        GarmID = 1,
        HelyaID = 2,

        Max
    };

    enum DataMisc
    {
        OdynIntroEvent,
        OdynEvadeComplete,
        OdynEventComplete1,
        OdynEventComplete2,
        OdynDefeated,
        OdynRunesActivated,
        OdynRunesDeactivated,
        OdynDeactivatedPurpleRune,
        OdynDeactivatedYellowRune,
        OdynDeactivatedBlueRune,
        OdynDeactivatedGreenRune,
        OdynDeactivatedOrangeRune,
        OdynTestOfAges
    };

    enum Creatures
    {
        // Odyn
        Odyn = 114263,
        Hymdall = 114361,
        Hyrja = 114360,
        DancingBlade = 114560,
        SpearOfLight = 114467,
        RagingTempest = 114485,
        ValarjarRunebearer = 114996,

        // Guarm
        Guarm = 114323,
        GuarmPassenger1 = 114341,
        GuarmPassenger2 = 114343,
        GuarmPassenger3 = 114344,

        // Helya
        Helya = 114537,
        DeepbrineMonstrosity = 114932,
        KvaldirReefcaller = 114539,
        DarkSeraph = 114922,
        KvaldirTideWitch = 114813,
        RotsoulGiant = 114548,
        AncientBonethrall = 114547,
        KvaldirCoralMaiden = 114811,
        GrippingTentacle = 114900,
        GrippingTentacle2 = 114901,
        GrippingTentacle3 = 114905,
        StrikingTentacle = 114881,
        OrbOfCorruption = 114523,
        NightWatchMariner = 114809,
        OrbOfCorrosion = 114566,
        DecayingMinion = 114568,
        KvaldirLongboat = 115941,
        Grimelord = 114709,
        HelarjarMistwatcher = 116335
    };

    enum GameObjects
    {
        GoTovOdynChest = 260526,
        GoRunicBrandPure = 245698,
        GoRunicBrandOrange = 245697,
        GoRunicBrandYellow = 245695,
        GoRunicBrandBlue = 245696,
        GoRunicBrandGreen = 245699,

        GoLightRay1 = 266889,
        GoLightRay2 = 266890,

        GoGarmDoor = 266532,
        GoGarmDoor2 = 266533,
        GoOdynDoor = 246145
    };
}

#define TrialOfValorScriptName "instance_trial_of_valor"

Position const NpcCosmeticOnePos = { 2417.55f, 548.087f, 749.078f, 5.21375f };
Position const NpcCosmeticTwoPos = { 2417.54f, 510.002f, 749.078f, 1.09311f };
Position const NpcCosmeticThreePos = { 2409.18f, 539.234f, 749.078f, 5.70767f };
Position const NpcCosmeticFourPos = { 2409.47f, 517.804f, 749.078f, 0.492901f };
Position const SpoilsPos = { 2412.46f, 528.816f, 749.078f, 0.0f };
Position const Odyn = { 498.5955f, 640.2118f, 86.31976f, 1.167363f };
Position const Hymdall = { 485.639f, 644.747f, 1.92648f, 1.16736f };
Position const ChosenofEyir[2] = {
    { 555.688f, 650.215f, 24.2717f, 5.14957f },
    { 542.759f, 600.101f, 24.4042f, 0.444993f }
};
Position const Eyir = { 519.887f, 630.771f, 19.2822f, 1.52475f };
Position const Hyrja = { 538.222f, 618.411f, 28.9495f, 1.95377f };
Position const StormforgedSentinel[3] = {
    { 463.908f, 664.0347f, 5.285385f, 0.3524198f },
    { 467.6684f, 656.8646f, 5.112077f, 0.4892152f },
    { 458.8663f, 671.7118f, 9.075208f, 0.2078661f }
};

#endif
