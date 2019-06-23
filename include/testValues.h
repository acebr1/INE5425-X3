#include "HypothesisTesting.h"

/* ------------------------------------------------------------
 * Data generated on Excel for T-Student distribution
------------------------------------------------------------ */
namespace TStudent {
    const int numN = 41; // Number of different values for n
    const int numQ = 10; // Number of different values for q

    // Values for n
    const double nValues[41] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 40.0, 45.0, 50.0, 60.0, 70.0, 80.0, 90.0, 100.0, 120.0, 150.0, 100000.0};
    // Values for q
    const double qValues[10] = {0.6, 0.7, 0.8, 0.9, 0.95, 0.975, 0.99, 0.995, 0.999, 0.9995};

    // Distribution table for given n/q values
    const double distribution[41][10] = {
    /*n \ q     0.6	            0.7	            0.8	            0.9	            0.95	        0.975           0.99            0.995	        0.999	        0.9995 */
    /*1*/  	    {0.3249196962,	0.7265425280,	1.3763819205,	3.0776835372,	6.3137515147,	12.7062047362,	31.8205159538,	63.6567411629,	318.3088389856,	636.6192487688},
    /*2*/  	    {0.2886751346,	0.6172133998,	1.0606601718,	1.8856180832,	2.9199855804,	4.3026527297,	6.9645567343,	9.9248432009,	22.3271247701,	31.5990545764},
    /*3*/  	    {0.2766706623,	0.5843897274,	0.9784723124,	1.6377443537,	2.3533634348,	3.1824463053,	4.5407028586,	5.8409093097,	10.2145318524,	12.9239786367},
    /*4*/  	    {0.2707222947,	0.5686490630,	0.9409645772,	1.5332062741,	2.1318467863,	2.7764451052,	3.7469473880,	4.6040948713,	7.1731822198,	8.6103015814},
    /*5*/  	    {0.2671808657,	0.5594296445,	0.9195437802,	1.4758840488,	2.0150483733,	2.5705818356,	3.3649299989,	4.0321429836,	5.8934295314,	6.8688266259},
    /*6*/  	    {0.2648345329,	0.5533809236,	0.9057032852,	1.4397557473,	1.9431802805,	2.4469118511,	3.1426684033,	3.7074280213,	5.2076262387,	5.9588161788},
    /*7*/  	    {0.2631668614,	0.5491096579,	0.8960296443,	1.4149239277,	1.8945786051,	2.3646242516,	2.9979515669,	3.4994832974,	4.7852896286,	5.4078825209},
    /*8*/  	    {0.2619210967,	0.5459337635,	0.8888895178,	1.3968153097,	1.8595480375,	2.3060041352,	2.8964594477,	3.3553873313,	4.5007909337,	5.0413054334},
    /*9*/  	    {0.2609553365,	0.5434802415,	0.8834038597,	1.3830287384,	1.8331129327,	2.2621571628,	2.8214379250,	3.2498355416,	4.2968056627,	4.7809125859},
    /*10*/ 	    {0.2601848295,	0.5415280388,	0.8790578286,	1.3721836411,	1.8124611228,	2.2281388520,	2.7637694581,	3.1692726726,	4.1437004940,	4.5868938587},
    /*11*/ 	    {0.2595558605,	0.5399378785,	0.8755299781,	1.3634303180,	1.7958848187,	2.2009851601,	2.7180791838,	3.1058065155,	4.0247010376,	4.4369793382},
    /*12*/ 	    {0.2590327457,	0.5386176682,	0.8726092916,	1.3562173340,	1.7822875556,	2.1788128297,	2.6809979931,	3.0545395894,	3.9296332646,	4.3177912836},
    /*13*/ 	    {0.2585908577,	0.5375040895,	0.8701515340,	1.3501712888,	1.7709333960,	2.1603686565,	2.6503088379,	3.0122758387,	3.8519823912,	4.2208317277},
    /*14*/ 	    {0.2582126539,	0.5365521798,	0.8680547816,	1.3450303745,	1.7613101358,	2.1447866879,	2.6244940676,	2.9768427344,	3.7873902375,	4.1404541127},
    /*15*/ 	    {0.2578853009,	0.5357291330,	0.8662449732,	1.3406056079,	1.7530503557,	2.1314495456,	2.6024802950,	2.9467128835,	3.7328344253,	4.0727651959},
    /*16*/ 	    {0.2575991949,	0.5350104529,	0.8646670018,	1.3367571673,	1.7458836763,	2.1199052992,	2.5834871853,	2.9207816224,	3.6861547927,	4.0149963272},
    /*17*/ 	    {0.2573470058,	0.5343774798,	0.8632790174,	1.3333793897,	1.7396067261,	2.1098155778,	2.5669339837,	2.8982305197,	3.6457673801,	3.9651262721},
    /*18*/ 	    {0.2571230426,	0.5338157505,	0.8620486680,	1.3303909436,	1.7340636066,	2.1009220402,	2.5523796302,	2.8784404727,	3.6104848848,	3.9216458251},
    /*19*/ 	    {0.2569228198,	0.5333138816,	0.8609505503,	1.3277282090,	1.7291328115,	2.0930240544,	2.5394831906,	2.8609346065,	3.5794001490,	3.8834058526},
    /*20*/ 	    {0.2567427539,	0.5328627916,	0.8599644397,	1.3253407070,	1.7247182429,	2.0859634473,	2.5279770027,	2.8453397098,	3.5518083432,	3.8495162749},
    /*21*/ 	    {0.2565799478,	0.5324551470,	0.8590740352,	1.3231878739,	1.7207429028,	2.0796138447,	2.5176480160,	2.8313595580,	3.5271536689,	3.8192771643},
    /*22*/ 	    {0.2564320343,	0.5320849613,	0.8582660517,	1.3212367416,	1.7171443744,	2.0738730679,	2.5083245529,	2.8187560606,	3.5049920311,	3.7921306717},
    /*23*/ 	    {0.2562970599,	0.5317472993,	0.8575295537,	1.3194602398,	1.7138715277,	2.0686576104,	2.4998667395,	2.8073356838,	3.4849643749,	3.7676268043},
    /*24*/ 	    {0.2561733983,	0.5314380561,	0.8568554581,	1.3178359337,	1.7108820799,	2.0638985616,	2.4921594732,	2.7969395048,	3.4667772980,	3.7453986193},
    /*25*/ 	    {0.2560596848,	0.5311537896,	0.8562361577,	1.3163450727,	1.7081407613,	2.0595385528,	2.4851071754,	2.7874358137,	3.4501887270,	3.7251439497},
    /*26*/ 	    {0.2559547657,	0.5308915918,	0.8556652333,	1.3149718643,	1.7056179198,	2.0555294386,	2.4786298236,	2.7787145333,	3.4349971816,	3.7066117435},
    /*27*/ 	    {0.2558576589,	0.5306489893,	0.8551372307,	1.3137029128,	1.7032884457,	2.0518305165,	2.4726599120,	2.7706829571,	3.4210336212,	3.6895917135},
    /*28*/ 	    {0.2557675234,	0.5304238649,	0.8546474856,	1.3125267816,	1.7011309343,	2.0484071418,	2.4671400980,	2.7632624555,	3.4081551784,	3.6739064007},
    /*29*/ 	    {0.2556836346,	0.5302143957,	0.8541919859,	1.3114336473,	1.6991270265,	2.0452296421,	2.4620213602,	2.7563859037,	3.3962402884,	3.6594050195},
    /*30*/ 	    {0.2556053650,	0.5300190039,	0.8537672615,	1.3104150254,	1.6972608866,	2.0422724563,	2.4572615424,	2.7499956536,	3.3851848668,	3.6459586350},
    /*40*/ 	    {0.2550386863,	0.5286056796,	0.8506997958,	1.3030770526,	1.6838510133,	2.0210753903,	2.4232567793,	2.7044592674,	3.3068777141,	3.5509657609},
    /*45*/ 	    {0.2548501002,	0.5281358519,	0.8496819047,	1.3006493323,	1.6794273927,	2.0141033889,	2.4121158757,	2.6895850194,	3.2814798482,	3.5202514650},
    /*50*/ 	    {0.2546993430,	0.5277604527,	0.8488692445,	1.2987136942,	1.6759050252,	2.0085591121,	2.4032719167,	2.6777932709,	3.2614090558,	3.4960128818},
    /*60*/ 	    {0.2544733950,	0.5271981272,	0.8476530064,	1.2958210935,	1.6706488649,	2.0002978220,	2.3901194726,	2.6602830289,	3.2317091260,	3.4602004692},
    /*70*/ 	    {0.2543121425,	0.5267970357,	0.8467862850,	1.2937628979,	1.6669144791,	1.9944371118,	2.3808074823,	2.6479046238,	3.2107890610,	3.4350145214},
    /*80*/ 	    {0.2541912796,	0.5264965293,	0.8461373479,	1.2922235831,	1.6641245786,	1.9900634213,	2.3738682730,	2.6386905963,	3.1952576903,	3.4163374585},
    /*90*/ 	    {0.2540973208,	0.5262629873,	0.8456332729,	1.2910288987,	1.6619610840,	1.9866745407,	2.3684974762,	2.6315651656,	3.1832708141,	3.4019353069},
    /*100*/	    {0.2540221825,	0.5260762706,	0.8452304245,	1.2900747613,	1.6602343261,	1.9839715185,	2.3642173662,	2.6258905214,	3.1737394937,	3.3904913112},
    /*120*/	    {0.2539095232,	0.5257963906,	0.8446268377,	1.2886462337,	1.6576508994,	1.9799304051,	2.3578246126,	2.6174211451,	3.1595387433,	3.3734537686},
    /*150*/	    {0.2537969220,	0.5255167450,	0.8440240736,	1.2872209136,	1.6550755002,	1.9759053309,	2.3514645818,	2.6090025659,	3.1454525320,	3.3565689817},
    /*100000*/	{0.2533477772,	0.5244021842,	0.8416248280,	1.2815600314,	1.6448688648,	1.9599877075,	2.3263851654,	2.5758784699,	3.0903138094,	3.2906240314}
    };
}

/* ------------------------------------------------------------
 * Data generated on Excel for Snedcor's F distribution
------------------------------------------------------------ */
namespace FSnedcor {
    const int numM = 34; // Number of different values for m
    const int numN = 14; // Number of different values for n

    // Values for m
    const double mValues[34] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0, 40.0, 60.0, 120.0, 100000.0};
    // Values for n
    const double nValues[14] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 20.0, 40.0, 120.0, 100000.0};

    // Distribution table for given n/m values with q = 0.95
    const double distribution95[34][14] = {
    /*m \ n	    1	                2	            3	            4	            5	            6	            7	            8	            9	            10	            20	            40	            120	            100000 */
    /*1*/   	{161.4476387976,	199.5000000000,	215.7073453696,	224.5832406263,	230.1618781101,	233.9860003563,	236.7684002770,	238.8826948025,	240.5432547133,	241.8817472508,	248.0130820847,	251.1431531328,	253.2528540334,	254.3131679815},
    /*2*/   	{18.5128205128,	    19.0000000000,	19.1642921275,	19.2467943448,	19.2964096520,	19.3295340152,	19.3532175361,	19.3709928981,	19.3848257182,	19.3958967236,	19.4457684906,	19.4707364323,	19.4873936002,	19.4957157462},
    /*3*/   	{10.1279644860,	    9.5520944959,	9.2766281531,	9.1171822532,	9.0134551675,	8.9406451208,	8.8867429556,	8.8452384600,	8.8122995552,	8.7855247105,	8.6601898019,	8.5944112500,	8.5493513668,	8.5264775298},
    /*4*/   	{7.7086474222,	    6.9442719100,	6.5913821164,	6.3882329087,	6.2560565022,	6.1631322827,	6.0942109257,	6.0410444761,	5.9987790312,	5.9643705522,	5.8025418933,	5.7169984055,	5.6581050079,	5.6281078070},
    /*5*/   	{6.6078909737,	    5.7861350433,	5.4094513181,	5.1921677728,	5.0503290576,	4.9502880687,	4.8758716958,	4.8183195357,	4.7724656131,	4.7350630697,	4.5581314974,	4.4637933244,	4.3984537682,	4.3650372211},
    /*6*/   	{5.9873776073,	    5.1432528498,	4.7570626631,	4.5336769503,	4.3873741874,	4.2838657138,	4.2066584879,	4.1468041623,	4.0990155417,	4.0599627943,	3.8741885810,	3.7742862848,	3.7046667086,	3.6689089500},
    /*7*/   	{5.5914478512,	    4.7374141278,	4.3468313999,	4.1203117269,	3.9715231506,	3.8659688531,	3.7870435399,	3.7257253171,	3.6766746989,	3.6365231206,	3.4445248321,	3.3404296518,	3.2674453435,	3.2297964954},
    /*8*/   	{5.3176550716,	    4.4589701075,	4.0661805514,	3.8378533546,	3.6874986663,	3.5805803198,	3.5004638550,	3.4381012334,	3.3881302347,	3.3471631202,	3.1503237735,	3.0427778211,	2.9669233207,	2.9276231336},
    /*9*/   	{5.1173550292,	    4.2564947291,	3.8625483576,	3.6330885114,	3.4816586539,	3.3737536470,	3.2927458389,	3.2295826127,	3.1788931045,	3.1372801079,	2.9364553922,	2.8259326537,	2.7475247882,	2.7067247915},
    /*10*/  	{4.9646027437,	    4.1028210151,	3.7082648190,	3.4780496908,	3.3258345304,	3.2171745474,	3.1354648046,	3.0716583853,	3.0203829470,	2.9782370161,	2.7740163983,	2.6608552072,	2.5801218735,	2.5379298971},
    /*11*/  	{4.8443356749,	    3.9822979571,	3.5874337024,	3.3566900211,	3.2038742627,	3.0946128879,	3.0123303430,	2.9479903186,	2.8962227613,	2.8536248583,	2.6464451537,	2.5309054970,	2.4480237989,	2.4045230240},
    /*12*/  	{4.7472253467,	    3.8852938347,	3.4902948195,	3.2591667269,	3.1058752391,	2.9961203775,	2.9133581790,	2.8485651421,	2.7963754895,	2.7533867688,	2.5435883297,	2.4258800588,	2.3409949059,	2.2962531034},
    /*13*/  	{4.6671927318,	    3.8055652530,	3.4105336446,	3.1791170525,	3.0254383001,	2.9152692387,	2.8320975016,	2.7669131819,	2.7143557891,	2.6710242286,	2.4588817718,	2.3391800329,	2.2524141991,	2.2064886893},
    /*14*/  	{4.6001099367,	    3.7388918324,	3.3438886781,	3.1122498480,	2.9582489131,	2.8477259959,	2.7641992568,	2.6986724187,	2.6457907352,	2.6021550510,	2.3878960551,	2.2663504961,	2.1778105498,	2.1307510994},
    /*15*/  	{4.5430771653,	    3.6823203437,	3.2873821046,	3.0555682759,	2.9012945362,	2.7904649974,	2.7066267822,	2.6407968829,	2.5876264352,	2.5437185497,	2.3275350090,	2.2042756836,	2.1140557444,	2.0659063843},
    /*16*/  	{4.4939984777,	    3.6337234676,	3.2388715175,	3.0069172799,	2.8524091651,	2.7413108283,	2.6571966002,	2.5910961799,	2.5376665389,	2.4935132213,	2.2755695852,	2.1507109695,	2.0588952366,	2.0096954715},
    /*17*/  	{4.4513217725,	    3.5915305685,	3.1967768409,	2.9647081100,	2.8099961745,	2.6986599016,	2.6142990451,	2.5479553578,	2.4942914946,	2.4499155004,	2.2303542822,	2.1039981422,	2.0106626831,	1.9604483381},
    /*18*/  	{4.4138734192,	    3.5545571457,	3.1599075898,	2.9277441728,	2.7728531530,	2.6613045229,	2.5767217293,	2.5101578954,	2.4562811492,	2.4117020398,	2.1906479256,	2.0628854465,	1.9680995154,	1.9169033537},
    /*19*/  	{4.3807496923,	    3.5218932606,	3.1273500051,	2.8951073075,	2.7400575417,	2.6283180383,	2.5435343014,	2.4767701475,	2.4226989371,	2.3779336873,	2.1554966371,	2.0264100552,	1.9302370988,	1.8780892876},
    /*20*/  	{4.3512435033,	    3.4928284767,	3.0983912121,	2.8660814020,	2.7108898372,	2.5989777116,	2.5140110630,	2.4470637480,	2.3928141084,	2.3478775670,	2.1241552129,	1.9938190987,	1.8963175446,	1.8432460175},
    /*21*/  	{4.3247937432,	    3.4668001115,	3.0724669864,	2.8400998075,	2.6847807302,	2.5727116405,	2.4875777037,	2.4204621974,	2.3660481920,	2.3209534393,	2.0960329766,	1.9645152656,	1.8657391550,	1.8117699000},
    /*22*/  	{4.3009495018,	    3.4433567794,	3.0491249887,	2.8167083396,	2.6612739171,	2.5490614138,	2.4637738300,	2.3965032838,	2.3419373277,	2.2966959569,	2.0706556612,	1.9380184963,	1.8380180013,	1.7831752945},
    /*23*/  	{4.2793443091,	    3.4221322079,	3.0279983823,	2.7955387374,	2.6399994261,	2.5276553252,	2.4422260857,	2.3748121258,	2.3201052423,	2.2747275850,	2.0476380469,	1.9139384758,	1.8127603294,	1.7570669277},
    /*24*/  	{4.2596772727,	    3.4028261054,	3.0087865704,	2.7762892893,	2.6206541479,	2.5081888234,	2.4226285334,	2.3550814948,	2.3002435225,	2.2547388307,	2.0266639716,	1.8919545331,	1.7896423911,	1.7331196936},
    /*25*/  	{4.2416990503,	    3.3851899614,	2.9912409095,	2.7587104697,	2.6029874028,	2.4904100181,	2.4047281081,	2.3370572241,	2.2820969852,	2.2364735811,	2.0074714988,	1.8718007187,	1.7683954677,	1.7110636522},
    /*26*/  	{4.2252012731,	    3.3690163595,	2.9751539640,	2.7425941372,	2.5867900871,	2.4741087808,	2.3883136780,	2.3205272350,	2.2654526743,	2.2197180737,	1.9898417526,	1.8532545685,	1.7487945904,	1.6906727302},
    /*27*/  	{4.2100084684,	    3.3541308285,	2.9603513184,	2.7277653060,	2.5718864058,	2.4591084426,	2.3732077116,	2.3053131774,	2.2501314772,	2.2042924928,	1.9735904039,	1.8361285306,	1.7306499329,	1.6717560974},
    /*28*/  	{4.1959718186,	    3.3403855582,	2.9466852660,	2.7140758041,	2.5581275011,	2.4452593951,	2.3592598541,	2.2912639841,	2.2359816607,	2.1900444889,	1.9585611023,	1.8202633492,	1.7138001646,	1.6541515074},
    /*29*/  	{4.1829642891,	    3.3276544986,	2.9340298897,	2.7013993319,	2.5453864879,	2.4324341046,	2.3463419220,	2.2782508491,	2.2228738339,	2.1768441283,	1.9446203518,	1.8055228996,	1.6981072629,	1.6377200982},
    /*30*/  	{4.1708767858,	    3.3158295010,	2.9222771906,	2.6896275737,	2.5335545476,	2.4205231886,	2.3343439648,	2.2661632741,	2.2106969833,	2.1645799171,	1.9316534752,	1.7917901186,	1.6834524220,	1.6223422924},
    /*40*/  	{4.0847457333,	    3.2317269928,	2.8387453980,	2.6059749491,	2.4494664264,	2.3358524048,	2.2490243251,	2.1801704532,	2.1240292640,	2.0772480464,	1.8388593490,	1.6927972097,	1.5766098616,	1.5089909245},
    /*60*/  	{4.0011913768,	    3.1504113106,	2.7580782958,	2.5252151020,	2.3682702357,	2.2540530099,	2.1665411560,	2.0969683125,	2.0400980555,	1.9925919966,	1.7479841331,	1.5942725201,	1.4672665163,	1.3893790114},
    /*120*/ 	{3.9201244090,	    3.0717794047,	2.6801675699,	2.4472365115,	2.2898512831,	2.1750062526,	2.0867702777,	2.0164256131,	1.9587632957,	1.9104610647,	1.6586801432,	1.4952023929,	1.3518864592,	1.2539974785},
    /*100000*/  {3.8415518137,	    2.9958220195,	2.6049980617,	2.3720210630,	2.2141888850,	2.0986880272,	2.0096826008,	1.9385062793,	1.8799796349,	1.8307981526,	1.5706269495,	1.3940857516,	1.2215690742,	1.0104573167}
    };

    // Distribution table for given n/m values with q = 0.975
    const double distribution975[34][14] = {
    /*m \ n	    1	                 2	                3	            4	            5	            6	            7	            8	            9	            10	            20	            40	                120	                 100000 */
    /*1*/       {647.7890114778,     799.5000000000,	864.1629721635,	899.5833101780,	921.8479032997,	937.1110834482,	948.2168890939,	956.6562206031,	963.2845789468,	968.6274436770,	993.1028045762,	1005.5980971658,	1014.0202388551,	 1018.2531734411},
    /*2*/       {38.5063291139,	     39.0000000000,	    39.1654945640,	39.2484176581,	39.2982277754,	39.3314579624,	39.3552052922,	39.3730220687,	39.3868832826,	39.3979745979,	39.4479113034,	39.4728954798,	    39.4895574579,	     39.4978802052},
    /*3*/       {17.4434433207,	     16.0441064293,	    15.4391823787,	15.1009789320,	14.8848229206,	14.7347184130,	14.6243950222,	14.5398865704,	14.4730806518,	14.4189420421,	14.1673813814,	14.0365090736,	    13.9472848515,	     13.9021192981},
    /*4*/       {12.2178626331,	     10.6491106407,	    9.9791985322,	9.6045298847,	9.3644708158,	9.1973110794,	9.0741410516,	8.9795804150,	8.9046816146,	8.8438809735,	8.5599431871,	8.4111323894,	    8.3091701480,	     8.2573845549},
    /*5*/       {10.0069821966,	     8.4336207394,	    7.7635894820,	7.3878857513,	7.1463818287,	6.9777018585,	6.8530756286,	6.7571720074,	6.6810543465,	6.6191543314,	6.3285552351,	6.1750497040,	    6.0692933530,	     6.0153806060},
    /*6*/       {8.8131006287,	     7.2598556801,	  	6.5987985220,	6.2271611644,	5.9875651260,	5.8197565790,	5.6954704737,	5.5996230050,	5.5234066240,	5.4613237187,	5.1684009381,	5.0124713843,	    4.9044456995,	     4.8491621465},
    /*7*/       {8.0726688801,	     6.5415202971,	  	5.8898191672,	5.5225943453,	5.2852368515,	5.1185966134,	4.9949092191,	4.8993406483,	4.8232170846,	4.7611164350,	4.4667396202,	4.3088760270,	    4.1989038270,	     4.1424010410},
    /*8*/       {7.5708820997,	     6.0594674375,	  	5.4159623396,	5.0526322174,	4.8172755553,	4.6516955373,	4.5285621474,	4.4332598892,	4.3572330650,	4.2951269602,	3.9994529707,	3.8397800939,	    3.7279403770,	     3.6702481803},
    /*9*/       {7.2092832475,	     5.7147053864,	  	5.0781186522,	4.7180784581,	4.4844113142,	4.3197218333,	4.1970466369,	4.1019556969,	4.0259941583,	3.9638651576,	3.6669055035,	3.5054738999,	    3.3917985610,	     3.3329241872},
    /*10*/      {6.9367281663,	     5.4563955259,	  	4.8256214934,	4.4683415782,	4.2360856682,	4.0721313151,	3.9498240689,	3.8548908797,	3.7789626341,	3.7167918646,	3.4185435162,	3.2553960638,	    3.1399144624,	     3.0798649462},
    /*11*/      {6.7241296602,	     5.2558893119,	  	4.6300249618,	4.2750715963,	4.0439982221,	3.8806511689,	3.7586379184,	3.6638190343,	3.5878986691,	3.5256717159,	3.2261447750,	3.0613302960,	    2.9440780047,	     2.8828644871},
    /*12*/      {6.5537687530,	     5.0958671658,	  	4.4741848096,	4.1212086185,	3.8911339339,	3.7282921154,	3.6065146422,	3.5117767363,	3.4358456419,	3.3735528498,	3.0727725236,	2.9063463656,	    2.7873651379,	     2.7250027440},
    /*13*/      {6.4142543003,	     4.9652657229,	  	4.3471780827,	3.9958975535,	3.7666740552,	3.6042563940,	3.4826693293,	3.3879873254,	3.3120324101,	3.2496679501,	2.9476708467,	2.7796926930,	    2.6590286210,	     2.5955354317},
    /*14*/      {6.2979386311,	     4.8566978607,	  	4.2417276304,	3.8919144378,	3.6634231140,	3.5013649360,	3.3799328777,	3.2852880186,	3.2093003409,	3.1468611936,	2.8436912228,	2.6742228162,	    2.5519244904,	     2.4873205271},
    /*15*/      {6.1995009378,	     4.7650482839,	  	4.1528040301,	3.8042713418,	3.5764153493,	3.4146646577,	3.2933598137,	3.1987380785,	3.1227117263,	3.0601968514,	2.7559019510,	2.5850053267,	    2.4611223959,	     2.3954288163},
    /*16*/      {6.1151271977,	     4.6866654011,	  	4.0768230620,	3.7294165456,	3.5021163355,	3.3406309395,	3.2194313183,	3.1248222143,	3.0487534580,	2.9861631744,	2.6807929608,	2.5085292152,	    2.3831113523,	     2.3163498617},
    /*17*/      {6.0420133440,	     4.6188743275,	  	4.0111631181,	3.6647540910,	3.4379437009,	3.2766890403,	3.1555770907,	3.0609727564,	2.9848594289,	2.9221949672,	2.6157991389,	2.4422276255,	    2.3153238214,	     2.2475162580},
    /*18*/      {5.9780524648,	     4.5596717127,	  	3.9538633649,	3.6083435719,	3.3819678059,	3.2209153075,	3.0998769017,	3.0052714457,	2.9291124931,	2.8663756788,	2.5590029738,	2.3841808121,	    2.2558389109,	     2.1870069594},
    /*19*/      {5.9216312623,	     4.5075279952,	  	3.9034284918,	3.5587060986,	3.3327183728,	3.1718442039,	3.0508678754,	2.9562568887,	2.8800520467,	2.8172450773,	2.5089426211,	2.3329244235,	    2.2031908294,	     2.1333558290},
    /*20*/      {5.8714937658,	     4.4612554959,	  	3.8586986663,	3.5146951623,	3.2890558457,	3.1283399619,	3.0074163305,	2.9127965262,	2.8365460861,	2.7736713752,	2.4644842975,	2.2873220449,	    2.1562415510,	     2.0854243689},
    /*21*/      {5.8266477642,	     4.4199181664,	  	3.8187606806,	3.4754084621,	3.2500835877,	3.0895089994,	2.9686303350,	2.8739992796,	2.7977039195,	2.7347639890,	2.4247352226,	2.2464782390,	    2.1140939384,	     2.0423148905},
    /*22*/      {5.7862991330,	     4.3827684395,	  	3.7828858591,	3.4401263263,	3.2150865810,	3.0546387834,	2.9337986715,	2.8391545839,	2.7628152464,	2.6998126514,	2.3889828527,	2.2096778451,	    2.0760310998,	     2.0033099046},
    /*23*/      {5.7498048257,	     4.3492021547,	  	3.7504857895,	3.4082678350,	3.1834877602,	3.0231542868,	2.9023473699,	2.8076889699,	2.7313067729,	2.6682440512,	2.3566516005,	2.1763427394,	    2.0414731876,	     1.9678289425},
    /*24*/      {5.7166386275,	     4.3187258075,	  	3.7210801909,	3.3793589877,	3.1548163425,	2.9945864111,	2.8738081880,	2.7791345812,	2.7027107536,	2.6395903911,	2.3272714446,	2.1460004692,	    2.0099460584,	     1.9353972323},
    /*25*/      {5.6863658098,	     4.2909323670,	  	3.6942732131,	3.3530092361,	3.1286844836,	2.9685487148,	2.8477953823,	2.7531059719,	2.6766418069,	2.6134662154,	2.3004547885,	2.1182611257,	    1.9810581624,	     1.9056225992},
    /*26*/      {5.6586241004,	     4.2654831614,	  	3.6697356977,	3.3288939259,	3.1047698175,	2.9447200079,	2.8239883357,	2.7292827555,	2.6527795760,	2.5895510797,	2.2758791486,	2.0928000380,	    1.9544832476,	     1.8781781772},
    /*27*/      {5.6331092096,	     4.2420941265,	  	3.6471917238,	3.3067409862,	3.0828022217,	2.9228311601,	2.8021183915,	2.7073964532,	2.6308555879,	2.5675764151,	2.2532740283,	2.0693446485,	    1.9299472408,	     1.8527892952},
    /*28*/      {5.6095636881,	     4.2205252421,	  	3.6264082804,	3.2863207155,	3.0625536632,	2.9026549809,	2.7819587522,	2.6872204052,	2.6106431712,	2.5473154503,	2.2324108432,	2.0476644361,	    1.9072181738,	     1.8292234059},
    /*29*/      {5.5877682578,	     4.2005723253,	  	3.6071872498,	3.2674378556,	3.0438303206,	2.8839983680,	2.7633166442,	2.6685619439,	2.5919496340,	2.5285753931,	2.2130951018,	2.0275630926,	    1.8860983607,	     1.8072822652},
    /*30*/      {5.5675349965,	     4.1820605910,	  	3.5893591204,	3.2499253786,	3.0264664092,	2.8666961540,	2.7460271763,	2.6512562592,	2.5746101337,	2.5111913014,	2.1951602741,	2.0088723859,	    1.8664182597,	     1.7867957953},
    /*40*/      {5.4239371516,	     4.0509920759,	  	3.4632596595,	3.1261141681,	2.9037223205,	2.7443815802,	2.6237809633,	2.5288634513,	2.4519392170,	2.3881610867,	2.0677140464,	1.8751973768,	    1.7242045323,	     1.6372385314},
    /*60*/      {5.2856105880,	     3.9252654442,	  	3.3425197265,	3.0076593684,	2.7863148041,	2.6273695921,	2.5067915201,	2.4116718163,	2.3344058520,	2.2701982624,	1.9444698188,	1.7440464276,	    1.5810341913,	     1.4822792421},
    /*120*/     {5.1523314829,	     3.8046381802,	  	3.2268902553,	2.8943084559,	2.6739883228,	2.5154008765,	2.3947943486,	2.2994098975,	2.2217296496,	2.1570114356,	1.8249196125,	1.6141473077,	    1.4326765684,	     1.3106081654},
    /*100000*/  {5.0240375072,	     3.6890155358,	  	3.1162646119,	2.7859490566,	2.5666265777,	2.4083550483,	2.2876637173,	2.1919446788,	2.1137679287,	2.0484455857,	1.7086184742,	1.4837009824,	    1.2686452929,	     1.0124731198}
    };

    // Distribution table for given n/m values with q = 0.99
    const double distribution99[34][14] = {
    /*m \ n	    1.0	                2.0	                 3.0	             4.0	             5.0	            6.0	                7.0	                8.0	                9.0	                10.0	            20.0	            40.0	            120.0	            100000.0 */
    /*1.0*/	    {4052.1806954768,	4999.5000000000,	 5403.3520137385,	 5624.5833296294,	 5763.6495541557,	5858.9861066862,	5928.3557315865,	5981.0703077977,	6022.4732449683,	6055.8467073958,	6208.7302217623,	6286.7820538529,	6339.3912746723,	6365.8325508639},
    /*2.0*/	    {98.5025125628,	    99.0000000000,	     99.1662013745,	     99.2493718553,	     99.2992964779,	    99.3325888654,	    99.3563737002,	    99.3742148189,	    99.3880927217,	    99.3991959745,	    99.4491708487,	    99.4741645672,	    99.4908293727,	    99.4991524734},
    /*3.0*/	    {34.1162215645,	    30.8165203505,	     29.4566951268,	     28.7098983873,	     28.2370808378,	    27.9106573577,	    27.6716960703,	    27.4891770305,	    27.3452063336,	    27.2287341215,	    26.6897905101,	    26.4108126893,	    26.2211387935,	    26.1252826120},
    /*4.0*/	    {21.1976895844,	    18.0000000000,	     16.6943692372,	     15.9770248526,	     15.5218575444,	    15.2068648612,	    14.9757577044,	    14.7988887906,	    14.6591335747,	    14.5459008033,	    14.0196086808,	    13.7453788947,	    13.5580963763,	    13.4631653315},
    /*5.0*/	    {16.2581770398,	    13.2739336120,       12.0599536917,	     11.3919280713,	     10.9670206509,	    10.6722547924,	    10.4555108918,	    10.2893110461,	    10.1577615479,	    10.0510172196,	    9.5526461618,	    9.2911887831,	    9.1117708515,	    9.0205276763},
    /*6.0*/	    {13.7450225333,	    10.9247665008,       9.7795382409,	     9.1483010302,	     8.7458952560,	    8.4661253405,	    8.2599952710,	    8.1016513667,	    7.9761213666,	    7.8741185336,	    7.3958318913,	    7.1432219023,	    6.9690230901,	    6.8801288455},
    /*7.0*/	    {12.2463833484,	    9.5465780211,        8.4512850531,	     7.8466450625,	     7.4604354930,	    7.1914047852,	    6.9928327787,	    6.8400490718,	    6.7187524818,	    6.6200626703,	    6.1554383856,	    5.9084485565,	    5.7372856284,	    5.6496308485},
    /*8.0*/	    {11.2586241433,	    8.6491106407,        7.5909919476,	     7.0060766230,	     6.6318251645,	    6.3706807302,	    6.1776242610,	    6.0288701066,	    5.9106188492,	    5.8142938551,	    5.3590949408,	    5.1156103957,	    4.9460515043,	    4.8589048915},
    /*9.0*/	    {10.5614310474,	    8.0215173099,        6.9919172222,	     6.4220854582,	     6.0569407141,	    5.8017703065,	    5.6128654774,	    5.4671225154,	    5.3511288611,	    5.2565419913,	    4.8079952288,	    4.5666487210,	    4.3977692285,	    4.3106556201},
    /*10.0*/	{10.0442892734,	    7.5594321575,        6.5523125575,	     5.9943386616,	     5.6363261877,	    5.3858110448,	    5.2001212505,	    5.0566931317,	    4.9424206521,	    4.8491468021,	    4.4053947664,	    4.1652868974,	    3.9964806910,	    3.9090862911},
    /*11.0*/	{9.6460341120,	    7.2057133505,        6.2167298115,	     5.6683002129,	     5.3160089186,	    5.0692104312,	    4.8860720392,	    4.7444676439,	    4.6315397476,	    4.5392818113,	    4.0990462487,	    3.8595729663,	    3.6904357025,	    3.6025493071},
    /*12.0*/	{9.3302121032,	    6.9266081402,        5.9525446815,	     5.4119514345,	     5.0643431111,	    4.8205735019,	    4.6395024466,	    4.4993652808,	    4.3875099632,	    4.2960544040,	    3.8584331027,	    3.6191813884,	    3.4494396705,	    3.3609169455},
    /*13.0*/	{9.0738057285,	    6.7009645359,        5.7393802828,	     5.2053301894,	     4.8616212079,	    4.6203633956,	    4.4409974107,	    4.3020620109,	    4.1910777818,	    4.1002672624,	    3.6646091040,	    3.4252927359,	    3.2547603649,	    3.1655017327},
    /*14.0*/	{8.8615926652,	    6.5148841022,        5.5638858397,	     5.0353779733,	     4.6949635794,	    4.4558200259,	    4.2778818533,	    4.1399460751,	    4.0296803369,	    3.9393963713,	    3.5052223399,	    3.2656412743,	    3.0941914937,	    3.0041280720},
    /*15.0*/	{8.6831168176,	    6.3588734807,        5.4169648578,	     4.8932095893,	     4.5556139847,	    4.3182730538,	    4.1415463070,	    4.0044531864,	    3.8947881071,	    3.8049397460,	    3.3718915821,	    3.1319055698,	    2.9594529754,	    2.8685373871},
    /*16.0*/	{8.5309652859,	    6.2262352803,        5.2922140455,	     4.7725779997,	     4.4374204955,	    4.2016337043,	    4.0259465907,	    3.8895721399,	    3.7804151699,	    3.6909314179,	    3.2587373638,	    3.0182483817,	    2.8447368301,	    2.7529370420},
    /*17.0*/	{8.3997401452,	    6.1121137158,        5.1849999173,	     4.6689676020,	     4.3359390832,	    4.1015053260,	    3.9267193883,	    3.7909641782,	    3.6822415240,	    3.5930661336,	    3.1615175366,	    2.9204578237,	    2.7458521673,	    2.6531472635},
    /*18.0*/	{8.2854195551,	    6.0129048348,        5.0918895204,	     4.5790359666,	     4.2478821502,	    4.0146365074,	    3.8406386599,	    3.7054218812,	    3.5970739135,	    3.5081617297,	    3.0770967202,	    2.8354204684,	    2.6597007920,	    2.5660780139},
    /*19.0*/	{8.1849468225,	    5.9258790223,        5.0102868436,	     4.5002576989,	     4.1707669806,	    3.9385726155,	    3.7652693946,	    3.6305245827,	    3.5225025399,	    3.4338168830,	    3.0031087717,	    2.7607862528,	    2.5839437840,	    2.4893964202},
    /*20.0*/	{8.0959580641,	    5.8489319246,        4.9381933823,	     4.4306901614,	     4.1026846306,	    3.8714268151,	    3.6987401521,	    3.5644120533,	    3.4566756315,	    3.3681863892,	    2.9377352774,	    2.6947486292,	    2.5167827911,	    2.4213086489},
    /*21.0*/	{8.0165969468,	    5.7804156882,        4.8740461970,	     4.3688151741,	     4.0421438612,	    3.8117254973,	    3.6395895582,	    3.5056317946,	    3.3981473576,	    3.3098295716,	    2.8795561928,	    2.6358963540,	    2.4568126134,	    2.3604128954},
    /*22.0*/	{7.9453857292,	    5.7190219125,        4.8166057778,	     4.3134294970,	     3.9879632231,	    3.7583014350,	    3.5866602243,	    3.4530335271,	    3.3457727566,	    3.2576055600,	    2.8274466970,	    2.5831111523,	    2.4029194300,	    2.3055978983},
    /*23.0*/	{7.8811336414,	    5.6636987681,        4.7648767594,	     4.2635674595,	     3.9391948547,	    3.7102183613,	    3.5390238779,	    3.4056947336,	    3.2986335974,	    3.2105994059,	    2.7805044380,	    2.5354955418,	    2.3542090266,	    2.2559713750},
    /*24.0*/	{7.8228705934,	    5.6135912115,        4.7180508075,	     4.2184452674,	     3.8950696548,	    3.6667167179,	    3.4959275205,	    3.3628671199,	    3.2559850745,	    3.1680689620,	    2.7379972347,	    2.4923209546,	    2.3099552112,	    2.2108085875},
    /*25.0*/	{7.7697984154,	    5.5679971343,        4.6754647823,	     4.1774202346,	     3.8549571647,	    3.6271739697,	    3.4567540466,	    3.3239374603,	    3.2172168262,	    3.1294060386,	    2.6993248392,	    2.4529898072,	    2.2695620992,	    2.1695147404},
    /*26.0*/	{7.7212544577,	    5.5263347139,        4.6365696243,	     4.1399604837,	     3.8183357628,	    3.5910751264,	    3.4209929973,	    3.2883985212,	    3.1818239903,	    3.0941075623,	    2.6639905476,	    2.4170073382,	    2.2325361136,	    2.1315970640},
    /*27.0*/	{7.6766840489,	    5.4881177684,        4.6009068947,	     4.1056221131,	     3.7847702132,	    3.5579905432,	    3.3882185369,	    3.2558271691,	    3.1493854107,	    3.0617538615,	    2.6315798261,	    2.3839604057,	    2.1984649020,	    2.0966437947},
    /*28.0*/	{7.6356193978,	    5.4529369212,        4.5680908637,	     4.0740317749,	     3.7538945388,	    3.5275589889,	    3.3580726588,	    3.2258676765,	    3.1195470206,	    3.0319921098,	    2.6017440139,	    2.3535013185,	    2.1670012597,	    2.0643081465},
    /*29.0*/	{7.5976632500,	    5.4204450403,        4.5377946778,	     4.0448732261,	     3.7253988048,	    3.4994745829,	    3.3302522296,	    3.1982188447,	    3.0920090251,	    3.0045235552,	    2.5741877518,	    2.3253353621,	    2.1378507259,	    2.0342959437},
    /*30.0*/	{7.5624760946,	    5.3903458632,        4.5097395625,	     4.0178768366,	     3.6990188114,	    3.4734766087,	    3.3044988867,	    3.1726239635,	    3.0665159079,	    2.9790935636,	    2.5486591801,	    2.2992110715,	    2.1107619103,	    2.0063559764},
    /*40.0*/	{7.3140999292,	    5.1785082359,        4.3125692125,	     3.8282935494,	     3.5138398331,	    3.2910123893,	    3.1237570566,	    2.9929808698,	    2.8875604403,	    2.8005451071,	    2.3688761223,	    2.1142324541,	    1.9171907833,	    1.8048499992},
    /*60.0*/	{7.0771057936,	    4.9774320354,        4.1258919308,	     3.6490474911,	     3.3388844224,	    3.1186742716,	    2.9530492080,	    2.8232802155,	    2.7184543867,	    2.6317507753,	    2.1978059063,	    1.9360184716,	    1.7263195116,	    1.6008107637},
    /*120.0*/	{6.8508934509,	    4.7865097397,        3.9490997925,	     3.4795313896,	     3.1735454752,	    2.9558540044,	    2.7917641097,	    2.6629056295,	    2.5585738821,	    2.4720767548,	    2.0345880631,	    1.7628487819,	    1.5329921831,	    1.3807422101},
    /*100000.0*/{6.6351498917,	    4.6053822684,        3.7818178516,	     3.3193631870,	     3.0174368368,	    2.8021618045,	    2.6395073929,	    2.5114563072,	    2.4075092392,	    2.3211016193,	    1.8784955011,	    1.5924730257,	    1.3248558853,	    1.0148219912}
    };
}

/* ------------------------------------------------------------
 * Data for diferent Average Tests
------------------------------------------------------------ */
namespace testAverageData {
    int numTests = 3;

    double sampleAvg1[]                     = {28, 		29,		105.5};
    double sampleStdDev1[]                  = {4.1, 	3.7,	20.1};
    unsigned long sampleNumElements1[]      = {15, 		17,		34};
	double confidencelevel[]                = {0.95,	0.95,	0.05};
    double sampleAvg2[]                     = {26,		26,		90.9};
    double sampleStdDev2[]                  = {3.8,		3.8,	12.2};
	unsigned long sampleNumElements2[]      = {10,		17,		29};
    HypothesisTesting::H1Comparition comp[] = {HypothesisTesting::H1Comparition::DIFFERENT, HypothesisTesting::H1Comparition::GREATER_THAN, HypothesisTesting::H1Comparition::DIFFERENT};
    double expectedResult[]                 = {0.231,	0.0131,	0.000824};
}

/* ------------------------------------------------------------
 * Data for diferent Proportion Tests
------------------------------------------------------------ */
namespace testProportionData {
    int numTests = 2;

	double sampleProp1[]					= {(52.0/69.0),		(130.0/750.0)};
	unsigned long sampleNumElements1[]		= {69,				750};
	double sampleProp2[]					= {(120.0/131.0),	(160.0/700.0)};
	unsigned long sampleNumElements2[]		= {131,				700};
	HypothesisTesting::H1Comparition comp[]	= {HypothesisTesting::H1Comparition::DIFFERENT, HypothesisTesting::H1Comparition::GREATER_THAN};
	double expectedResult[]					= {0.0016,			0.0043};
}

/* ------------------------------------------------------------
 * Data for diferent Variance Tests
------------------------------------------------------------ */
namespace testVarianceData {
    int numTests = 2;

	double sampleVar1[]						= {0.683,	65.549};
	unsigned long sampleNumElements1[]		= {10,		240};
	double sampleVar2[]						= {0.750,	61.854};
	unsigned long sampleNumElements2[]		= {10,		240};
	HypothesisTesting::H1Comparition comp[]	= {HypothesisTesting::H1Comparition::DIFFERENT, HypothesisTesting::H1Comparition::DIFFERENT};
	double expectedResult[]					= {0.891,	0.654};
}
