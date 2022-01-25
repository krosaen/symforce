// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     measurements.cc.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#include <vector>

#include <Eigen/Dense>

#include <sym/pose3.h>
#include <sym/util/typedefs.h>

namespace robot_3d_localization {

// Measurement values for matching factors.
extern const std::vector<std::vector<Eigen::Vector3d>> body_t_landmark_measurements{
    {Eigen::Vector3d(3.7815647909783885, 9.442631088638649, 7.356078978664892),
     Eigen::Vector3d(6.140388498616963, 1.55660380051337, 1.716409568943427),
     Eigen::Vector3d(0.31886161127302015, 8.743951708186874, 6.019854824255905),
     Eigen::Vector3d(7.050825042913868, 0.2150210206115747, 9.500341630159854),
     Eigen::Vector3d(8.302459219220466, 2.159102363933936, 1.9660390765451579),
     Eigen::Vector3d(1.7822180767069735, 2.9615730693060582, 5.197388611963925),
     Eigen::Vector3d(4.410990398191365, 2.945166512946388, 6.065552926847091),
     Eigen::Vector3d(1.446265349831754, 2.9311542402869857, 3.760482931990206),
     Eigen::Vector3d(4.490494532782624, 7.81899339927036, 1.9575270062703816),
     Eigen::Vector3d(4.995992889322904, 5.953757716326883, 0.49060965441796617),
     Eigen::Vector3d(6.075959864678629, 1.6817825235354007, 0.5089788556477537),
     Eigen::Vector3d(9.446790840256797, 9.622048879092917, 8.003745754242448),
     Eigen::Vector3d(3.030009120567106, 1.0171262257452924, 7.030948855242622),
     Eigen::Vector3d(4.418982718679198, 1.2461373875200648, 4.944324509536085),
     Eigen::Vector3d(0.1520080896222798, 9.090552633242899, 2.593822836994272),
     Eigen::Vector3d(6.871547054788349, 3.0978746644159973, 5.23083494601147),
     Eigen::Vector3d(5.463631616462272, 1.7316767514933171, 9.810128559097087),
     Eigen::Vector3d(7.826521536879823, 9.474092610346196, 8.857334758797014),
     Eigen::Vector3d(6.119279219204461, 9.07855724395194, 0.943610729899222),
     Eigen::Vector3d(2.17887418677245, 0.3532192565923118, 3.1966735346723665)},
    {Eigen::Vector3d(-1.0204381333441161, 5.0303821285830335, 6.904285666191198),
     Eigen::Vector3d(2.2690726020394876, 0.24025609869202613, -1.145570559858886),
     Eigen::Vector3d(-3.623816465400373, 2.7926102579717385, 6.516360127942959),
     Eigen::Vector3d(7.1660455806980785, -0.577511401922054, 5.30984434127377),
     Eigen::Vector3d(3.8657814023718253, 2.2801616621785583, -1.6695369799939606),
     Eigen::Vector3d(-0.04140581070655353, -1.1004028824549321, 3.9327959545201736),
     Eigen::Vector3d(2.11789271858977, 0.02837906357210654, 3.894457212438525),
     Eigen::Vector3d(-0.9657200781682761, -1.348872186897438, 2.5551631344186796),
     Eigen::Vector3d(-1.886269040001257, 4.598879875899562, 1.5329728024210938),
     Eigen::Vector3d(-1.119319892876746, 3.6451861266207373, -0.5844760018907378),
     Eigen::Vector3d(1.7534813470801343, 0.6426316418071687, -2.097294467473933),
     Eigen::Vector3d(3.6127912300550515, 8.61838418595548, 5.952562110412776),
     Eigen::Vector3d(2.667262785483293, -2.1564813866700523, 4.39579639213625),
     Eigen::Vector3d(2.8602722193527637, -1.1066562407212261, 2.1849082001642426),
     Eigen::Vector3d(-5.458955134998026, 2.997377943276902, 3.690751503802817),
     Eigen::Vector3d(3.519144942174769, 1.761552961224119, 2.448816347704534),
     Eigen::Vector3d(5.151413108748263, -0.12597856949422925, 6.3848304322613085),
     Eigen::Vector3d(2.9960581795982857, 7.2812050195254665, 7.185756351126006),
     Eigen::Vector3d(-2.0205196079593484, 6.632769415811845, 0.4460710997089884),
     Eigen::Vector3d(0.5808132040689838, -2.9671885569690177, 1.2372179035706068)},
    {Eigen::Vector3d(-0.2933074510769572, -0.8335367249723327, 6.4508211853199136),
     Eigen::Vector3d(1.281022657258331, -2.013700351776858, -3.505970437288834),
     Eigen::Vector3d(-1.0282047554292109, -4.0492445231479195, 6.029302638386898),
     Eigen::Vector3d(8.22145438022603, -0.40776252489330567, 0.6873618165065416),
     Eigen::Vector3d(1.3720477474112125, 0.4238737622965232, -3.5089354112240994),
     Eigen::Vector3d(2.426836585092625, -5.060037703894674, 1.3658336451048771),
     Eigen::Vector3d(3.4453434551948656, -2.4854242216151845, 1.1760267430573832),
     Eigen::Vector3d(1.5672859215299701, -5.521722380030902, 0.5797156813712646),
     Eigen::Vector3d(-2.7880304783848655, -1.1113366498748143, 1.5301381174741446),
     Eigen::Vector3d(-2.560459576714745, -1.5641263709470927, -0.9608909516687404),
     Eigen::Vector3d(0.3972903735865495, -2.01349614889601, -3.69213428803046),
     Eigen::Vector3d(0.8692191275494748, 4.888726338089453, 5.022545272512317),
     Eigen::Vector3d(4.9891778543457015, -4.17556069233635, 0.7575252074614668),
     Eigen::Vector3d(3.573143760975415, -3.256793415601013, -0.7382451669400237),
     Eigen::Vector3d(-3.9437590030199803, -4.5869097195923105, 4.196459378645634),
     Eigen::Vector3d(2.8439028606751036, -0.22399783668914275, -0.062145770182141194),
     Eigen::Vector3d(6.678770889594338, -1.3427810525521138, 2.3629810011785795),
     Eigen::Vector3d(1.7041773551704247, 3.1458484026085887, 6.158917352325981),
     Eigen::Vector3d(-4.359532200338161, 0.5497676590287808, 1.1296658877716164),
     Eigen::Vector3d(2.5753218607625454, -5.989480715091984, -1.7007778915262297)},
    {Eigen::Vector3d(3.720645843602691, -2.46113854688388, 3.43535181759963),
     Eigen::Vector3d(1.2204215057123198, -1.8995565150653029, -6.10097205023442),
     Eigen::Vector3d(4.331860776684303, -5.76890483155427, 2.593563287062822),
     Eigen::Vector3d(7.26740450871841, 3.055225909892727, -4.010705297657143),
     Eigen::Vector3d(-0.17658717010226505, -0.07526753515295279, -6.072752130166676),
     Eigen::Vector3d(5.375611534460282, -4.141921319929572, -3.1506104284034966),
     Eigen::Vector3d(5.096231153955311, -1.6809178149713124, -2.9946447104891436),
     Eigen::Vector3d(4.549285912635439, -5.101989646220222, -3.9134692074238435),
     Eigen::Vector3d(-0.17681705863143315, -4.129734196064049, -0.32657652355136135),
     Eigen::Vector3d(-0.955572266228494, -4.0494801586856255, -2.7165733327766812),
     Eigen::Vector3d(0.3369647950655306, -2.5404517224708902, -6.449655941134398),
     Eigen::Vector3d(1.217337690390281, 2.9355761698333365, 3.4942134267314846),
     Eigen::Vector3d(7.110857457231823, -2.163326076590649, -4.324880745358017),
     Eigen::Vector3d(4.723954577735061, -1.7369152296716817, -5.03955496360426),
     Eigen::Vector3d(1.7922655278755093, -7.710594106979769, 1.3773451998205137),
     Eigen::Vector3d(3.0625391218701306, -0.0030361255593182312, -3.380283130024093),
     Eigen::Vector3d(7.5980171456819745, 1.3917075724974504, -2.4095936582421706),
     Eigen::Vector3d(2.861971988900131, 1.665646960764283, 3.8092044296481617),
     Eigen::Vector3d(-2.3295260062176992, -3.6130552440893156, 0.44102367721226915),
     Eigen::Vector3d(4.920335152171241, -4.437862629367494, -6.27496307186612)},
    {Eigen::Vector3d(4.585250938938217, 0.025285730305881826, 0.22046216271565755),
     Eigen::Vector3d(-1.4844538259129783, -0.30875958157717315, -7.65449447807006),
     Eigen::Vector3d(6.540073314118765, -1.9347278615011603, -1.9215790637294043),
     Eigen::Vector3d(1.3352895317020343, 7.268229079619759, -6.219512104552126),
     Eigen::Vector3d(-3.3408626368583, 0.5824369071257206, -6.4286840909909895),
     Eigen::Vector3d(4.240454560083471, 0.2105854786282504, -6.9091758243982175),
     Eigen::Vector3d(2.460432961564898, 2.1537620250714307, -5.726073712791779),
     Eigen::Vector3d(3.645726277441199, -1.1036029356759807, -7.596629391707202),
     Eigen::Vector3d(0.8841092607155439, -3.3250524577518816, -2.3953837689557593),
     Eigen::Vector3d(-0.7242747025539924, -3.540352332487869, -4.486118983159061),
     Eigen::Vector3d(-2.0636932764467057, -1.2122572038939374, -7.921231649076392),
     Eigen::Vector3d(0.10115766736493662, 2.9406223553648356, 2.5403432174013787),
     Eigen::Vector3d(3.4208761685706475, 2.9879612674290126, -7.892203537240427),
     Eigen::Vector3d(1.264579114103803, 1.7991096976684169, -7.628311489663945),
     Eigen::Vector3d(4.983378904198355, -4.8492560162662395, -2.5929926046688085),
     Eigen::Vector3d(-0.05399946718085936, 2.168625706851518, -5.171195459935742),
     Eigen::Vector3d(3.001690337058933, 5.863533825342262, -5.2703527513748),
     Eigen::Vector3d(1.8589988206612713, 3.081142008539771, 2.158183030799384),
     Eigen::Vector3d(-0.6707370396188891, -4.125168436658443, -1.034140179941739),
     Eigen::Vector3d(2.4478969317022536, -0.14725277089732453, -9.630632141726206)}};

// Measurement values for odometry factors.
extern const std::vector<sym::Pose3d> odometry_relative_pose_measurements{
    sym::Pose3d((sym::Vector7d() << -0.13501215628331673, -0.20222966894293337, -0.3089595042532179,
                 0.919466640714369, 3.9292098215939313, 2.849876607288219, 1.3574926855557967)
                    .finished()),
    sym::Pose3d((sym::Vector7d() << -0.08963529380100402, -0.20830988195789618,
                 -0.30621161700461097, 0.9245577065793766, 1.6374397495612032, 3.808015692837227,
                 1.4118193972427464)
                    .finished()),
    sym::Pose3d((sym::Vector7d() << -0.12106512049280166, -0.1955485453284592, -0.2886010882784062,
                 0.9294156308479574, -0.1267266870450805, 1.9891012585992818, 1.5763688162409306)
                    .finished()),
    sym::Pose3d((sym::Vector7d() << -0.13604542201817596, -0.2129040170822517, -0.2763255138306719,
                 0.9272581803706841, 0.45646194108076704, -0.32594178887384007, 1.6389636380544312)
                    .finished())};

// Landmark positions.
extern const std::vector<Eigen::Vector3d> landmark_positions{
    Eigen::Vector3d(3.745401188473625, 9.50714306409916, 7.319939418114051),
    Eigen::Vector3d(5.986584841970366, 1.5601864044243652, 1.5599452033620265),
    Eigen::Vector3d(0.5808361216819946, 8.661761457749352, 6.011150117432088),
    Eigen::Vector3d(7.080725777960454, 0.20584494295802447, 9.699098521619943),
    Eigen::Vector3d(8.324426408004218, 2.1233911067827616, 1.8182496720710062),
    Eigen::Vector3d(1.8340450985343382, 3.0424224295953772, 5.247564316322379),
    Eigen::Vector3d(4.319450186421157, 2.9122914019804194, 6.118528947223795),
    Eigen::Vector3d(1.3949386065204183, 2.9214464853521815, 3.663618432936917),
    Eigen::Vector3d(4.56069984217036, 7.851759613930136, 1.9967378215835974),
    Eigen::Vector3d(5.142344384136116, 5.924145688620425, 0.46450412719997725),
    Eigen::Vector3d(6.075448519014383, 1.7052412368729153, 0.6505159298527952),
    Eigen::Vector3d(9.488855372533333, 9.656320330745594, 8.08397348116461),
    Eigen::Vector3d(3.0461376917337066, 0.9767211400638387, 6.842330265121569),
    Eigen::Vector3d(4.4015249373960135, 1.2203823484477883, 4.951769101112702),
    Eigen::Vector3d(0.34388521115218396, 9.093204020787821, 2.587799816000169),
    Eigen::Vector3d(6.62522284353982, 3.1171107608941098, 5.200680211778108),
    Eigen::Vector3d(5.4671027934327965, 1.8485445552552704, 9.695846277645586),
    Eigen::Vector3d(7.7513282336111455, 9.394989415641891, 8.948273504276488),
    Eigen::Vector3d(5.978999788110851, 9.218742350231167, 0.884925020519195),
    Eigen::Vector3d(1.959828624191452, 0.45227288910538066, 3.2533033076326436)};

}  // namespace robot_3d_localization
