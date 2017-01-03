###############################################################################
# TEST geomatics applications: DDBase and DiscFix
###############################################################################

###############################################################################
# @todo - DDBase: Check that -h/--help is handled properly
###############################################################################
#add_test(NAME DDBase_CmdOpt_help
#         COMMAND ${CMAKE_COMMAND
#         -DTEST_PROG=$<TARGET_FILE:DDBase>
#         -DSOURCEDIR=${GPSTK_TEST_DATA_DIR}
#         -DTARGETDIR=${GPSTK_TEST_OUTPUT_DIR}
#         -P ${CMAKE_SOURCE_DIR}/core/tests/testhelp.cmake)

# ! ! ! WARNING ! ! !  DDBase currently only accepts command-line parameters
#                      with a very particular syntax:
#
# -fFILE       Accepted
# -f FILE      Rejected
# --fileFILE   Rejected
# --file FILE  Accepted
# --file=FILE  Rejected
#
# This unfortunate situation complicates the passing of parameters to the
# other cmake scripts - only -DARGS handles them adequately.  Thus, the tests
# below pass all parameters via ARGS with escaped spaces; SPARG{1-4} won't work.


###############################################################################
# DDBase: [-f|--file] <file>  Name of file containing more options
###############################################################################

# Missing options file
add_test(NAME DDBase_CmdOpt_f_missing
         COMMAND ${CMAKE_COMMAND}
         -DTEST_PROG=$<TARGET_FILE:DDBase>
         -DARGS="-f missingFile"
         -P ${CMAKE_SOURCE_DIR}/core/tests/testfailexp.cmake)

# Present but invalid options file
add_test(NAME DDBase_CmdOpt_f_invalid
         COMMAND ${CMAKE_COMMAND}
         -DTEST_PROG=$<TARGET_FILE:DDBase>
         -DARGS="-f ${GPSTK_TEST_DATA_DIR}/test_input_ddbase.sp3"
         -P ${CMAKE_SOURCE_DIR}/core/tests/testfailexp.cmake)

# Valid options file - includes valid --ObsFile, --NavFile, --DT, --BeginTime,
# --EndTime, --EOPFile, --PosXYZ, --Fix, --PosPRS, and --BaseOut
add_test(NAME DDBase_CmdOpt_f_valid
         COMMAND ${CMAKE_COMMAND}
         -DTEST_PROG=$<TARGET_FILE:DDBase>
         -DTARGETDIR=${GPSTK_TEST_OUTPUT_DIR}
         -DNODIFF=TRUE
         -DARGS=-f${GPSTK_TEST_DATA_DIR}/test_input_ddbase.opt_ok\ --ObsPath\ ${GPSTK_TEST_DATA_DIR}\ --NavPath\ ${GPSTK_TEST_DATA_DIR}\ --EOPPath\ ${GPSTK_TEST_DATA_DIR}
         -P ${CMAKE_SOURCE_DIR}/core/tests/testsuccexp.cmake)


###############################################################################
# DDBase: --Log <file>  Name of output log file (ddbase.log)
###############################################################################

# Valid options file plus a valid log file
add_test(NAME DDBase_CmdOpt_log_valid
         COMMAND ${CMAKE_COMMAND}
         -DTEST_PROG=$<TARGET_FILE:DDBase>
         -DTARGETDIR=${GPSTK_TEST_OUTPUT_DIR}
         -DNODIFF=TRUE
         -DARGS=-f${GPSTK_TEST_DATA_DIR}/test_input_ddbase.opt_ok\ --ObsPath\ ${GPSTK_TEST_DATA_DIR}\ --NavPath\ ${GPSTK_TEST_DATA_DIR}\ --EOPPath\ ${GPSTK_TEST_DATA_DIR}\ --Log\ ${GPSTK_TEST_OUTPUT_DIR}/test_output_ddbase.log
         -P ${CMAKE_SOURCE_DIR}/core/tests/testsuccexp.cmake)

# Valid options file plus an invalid log file
add_test(NAME DDBase_CmdOpt_log_invalid
         COMMAND ${CMAKE_COMMAND}
         -DTEST_PROG=$<TARGET_FILE:DDBase>
         -DTARGETDIR=${GPSTK_TEST_OUTPUT_DIR}
         -DNODIFF=TRUE
         -DARGS=-f${GPSTK_TEST_DATA_DIR}/test_input_ddbase.opt_ok\ --ObsPath\ ${GPSTK_TEST_DATA_DIR}\ --NavPath\ ${GPSTK_TEST_DATA_DIR}\ --EOPPath\ ${GPSTK_TEST_DATA_DIR}\ --Log\ ${GPSTK_TEST_OUTPUT_DIR}/floop/derp/test_output_ddbase.log
         -P ${CMAKE_SOURCE_DIR}/core/tests/testfailexp.cmake)


###############################################################################
# DDBase: --ObsPath <path>      Path for input obs file(s) ()
###############################################################################

# Valid options file plus an invalid obs path
add_test(NAME DDBase_CmdOpt_obspath_invalid
         COMMAND ${CMAKE_COMMAND}
         -DTEST_PROG=$<TARGET_FILE:DDBase>
         -DTARGETDIR=${GPSTK_TEST_OUTPUT_DIR}
         -DNODIFF=TRUE
         -DARGS=-f${GPSTK_TEST_DATA_DIR}/test_input_ddbase.opt_ok\ --ObsPath\ ${GPSTK_TEST_DATA_DIR}/floop/derp\ --NavPath\ ${GPSTK_TEST_DATA_DIR}\ --EOPPath\ ${GPSTK_TEST_DATA_DIR}
         -P ${CMAKE_SOURCE_DIR}/core/tests/testfailexp.cmake)


###############################################################################
# DDBase: --ObsFile <name,id>   RINEX obs file name, and station label [repeatable] ()
###############################################################################

# Valid options file plus an invalid obs file
add_test(NAME DDBase_CmdOpt_obsfile_invalid
         COMMAND ${CMAKE_COMMAND}
         -DTEST_PROG=$<TARGET_FILE:DDBase>
         -DTARGETDIR=${GPSTK_TEST_OUTPUT_DIR}
         -DNODIFF=TRUE
         -DARGS=-f${GPSTK_TEST_DATA_DIR}/test_input_ddbase.opt_ok\ --ObsPath\ ${GPSTK_TEST_DATA_DIR} --NavPath\ ${GPSTK_TEST_DATA_DIR}\ --EOPPath\ ${GPSTK_TEST_DATA_DIR}\ --ObsFile\ missing_obs_file
         -P ${CMAKE_SOURCE_DIR}/core/tests/testfailexp.cmake)


###############################################################################
# DDBase: --NavPath <dir>       Path of navigation file(s) ()
###############################################################################

# Valid options file plus an invalid nav path
add_test(NAME DDBase_CmdOpt_navpath_invalid
         COMMAND ${CMAKE_COMMAND}
         -DTEST_PROG=$<TARGET_FILE:DDBase>
         -DTARGETDIR=${GPSTK_TEST_OUTPUT_DIR}
         -DNODIFF=TRUE
         -DARGS=-f${GPSTK_TEST_DATA_DIR}/test_input_ddbase.opt_ok\ --ObsPath\ ${GPSTK_TEST_DATA_DIR} --NavPath\ ${GPSTK_TEST_DATA_DIR}/floop/derp\ --EOPPath\ ${GPSTK_TEST_DATA_DIR}\ --ObsFile\ missing_obs_file
         -P ${CMAKE_SOURCE_DIR}/core/tests/testfailexp.cmake)


###############################################################################
# DDBase: --NavFile <file>      Navigation (RINEX nav OR SP3) file name [repeatable] ()
###############################################################################

# Valid options file plus an invalid nav file
add_test(NAME DDBase_CmdOpt_navfile_invalid
         COMMAND ${CMAKE_COMMAND}
         -DTEST_PROG=$<TARGET_FILE:DDBase>
         -DTARGETDIR=${GPSTK_TEST_OUTPUT_DIR}
         -DNODIFF=TRUE
         -DARGS=-f${GPSTK_TEST_DATA_DIR}/test_input_ddbase.opt_ok\ --ObsPath\ ${GPSTK_TEST_DATA_DIR} --NavPath\ ${GPSTK_TEST_DATA_DIR}\ --EOPPath\ ${GPSTK_TEST_DATA_DIR}\ --NavFile\ missing_nav_file
         -P ${CMAKE_SOURCE_DIR}/core/tests/testfailexp.cmake)


###############################################################################
# DDBase: --EOPPath <dir>       Path of earth orientation file(s) ()
###############################################################################

# Valid options file plus an invalid eop path
add_test(NAME DDBase_CmdOpt_eoppath_invalid
         COMMAND ${CMAKE_COMMAND}
         -DTEST_PROG=$<TARGET_FILE:DDBase>
         -DTARGETDIR=${GPSTK_TEST_OUTPUT_DIR}
         -DNODIFF=TRUE
         -DARGS=-f${GPSTK_TEST_DATA_DIR}/test_input_ddbase.opt_ok\ --ObsPath\ ${GPSTK_TEST_DATA_DIR} --NavPath\ ${GPSTK_TEST_DATA_DIR}\ --EOPPath\ ${GPSTK_TEST_DATA_DIR}/floop/derp\ --ObsFile\ missing_obs_file
         -P ${CMAKE_SOURCE_DIR}/core/tests/testfailexp.cmake)


###############################################################################
# DDBase: --EOPFile <file>      Earth orientation parameter (EOPP or IERS format) file [repeatable].
###############################################################################

# Valid options file plus an invalid eop file
add_test(NAME DDBase_CmdOpt_eopfile_invalid
         COMMAND ${CMAKE_COMMAND}
         -DTEST_PROG=$<TARGET_FILE:DDBase>
         -DTARGETDIR=${GPSTK_TEST_OUTPUT_DIR}
         -DNODIFF=TRUE
         -DARGS=-f${GPSTK_TEST_DATA_DIR}/test_input_ddbase.opt_ok\ --ObsPath\ ${GPSTK_TEST_DATA_DIR} --NavPath\ ${GPSTK_TEST_DATA_DIR}\ --EOPPath\ ${GPSTK_TEST_DATA_DIR}\ --EOPFile\ missing_eop_file
         -P ${CMAKE_SOURCE_DIR}/core/tests/testfailexp.cmake)

# @todo - Valid IERS input file

# @todo - Invalid IERS input file

# @todo - If no EOP file is given, DDBase will search for a default IERS
#         format file in the current directory.] (finals.daily)
#


###############################################################################
# @todo - DDBase: Station configuration   [--Pos.. (1 only) MUST be given for each site]:
###############################################################################
# --PosXYZ <X,Y,Z,id>   Station position in ECEF coordinates in m,
#                         followed by a label identifying the station. ()
# --PosLLH <La,Lo,H,id> Station position in geodetic coordinates:
#                         Latitude(deg),Longitude(E,deg),Height(m),label ()
# --PosPRS <id>         Let position of station labelled <id> be set to the computed
#                         average pseudorange solution for that site. ()
###############################################################################


###############################################################################
# @todo - DDBase: --TropModel <trop,id> Use trop model <trop> for station <id>,
#                    choices are: 'Zero','Black','NewB','ModHop','ModHopH',
#                    'Saas' [cf. GPSTk] (Saas)
###############################################################################


###############################################################################
# @todo - DDBase: --Weather <T,P,H,id>  Weather parameters: Temperature(degC),
#                    Pressure(mbar), Humidity(%), followed by a label
#                    identifying the station. (20.0,1010.00,50.0)
###############################################################################


###############################################################################
# @todo - DDBase: --Fix <id>  Hold the station <id> fixed in estimation [repeatable] (don't)
###############################################################################


###############################################################################
## @todo - DDBase Configuration:
###############################################################################
# --noEstimate          Quit before performing the estimation. (don't)
# --Freq <L1|L2|L3>     Process L1, L2 or L3 [L1+L2] frequency data [L3 not validated] (L1)
# --nIter <n>           Maximum number of estimation iterations (5)
# --Converge <cl>       Convergence limit on RSS change in state in meters (5.00e-08)
# --FixBiases           Perform an extra, last iteration that fixes the phase biases (don't)
#
## Model, state elements, a priori constraints:
# --RZDnIntervals <n>   Number of (equal time) residual zenith delay intervals (0)
#                         [enter 0 to turn off estimation of RZD]
# --RZDtimeconst <tau>  Time constant in hours for multiple RZD intervals (2.00)
# --RZDsigma <sig>      A priori sigma in m for residual zenith delay (0.50)
# --Tight <ppm>         Tight a priori constraint, a fraction of baseline (0.0001)
# --Loose <ppm>         Loose a priori constraint, a fraction of baseline (0.1)
#
## Time limits:
# --BeginTime <arg>     Start time: arg = 'GPSweek,sow' OR 'YYYY,M,D,H,Min,Sec' ()
# --EndTime <arg>       End time: arg = 'GPSweek,sow' OR 'YYYY,M,D,H,Min,Sec' ()
#
## Satellite time table:
# --TimeTable <file>    Time table file name [if this option does not appear
#                          a time table will be computed and output to log file] ()
# --Ref <sat>           Use <sat> as 'reference' in DDs; don't use a timetable ()
#
## Data editing:
# --MinElev <elev>      Ignore data below elevation <elev> degrees, DDs only (10.00)
# --AntRotElev <elev>   Apply MinElev to antenna rotated in elevation by <elev> deg. ()
# --AntRotAz <az>       Apply MinElev to antenna rotated in azimuth by <az> deg. ()
# --MaxGap <n>          Maximum acceptable gap in data [number of --DT intervals] (10)
# --MinDDSeg <n>        Minimum acceptable length of DD data segment (50)
# --PhaseBiasReset <n>  Limit on pt-to-pt change in phase without reset, in cycles (10)
# --XSat <sat>          Exclude this satellite [repeatable] ()
# --DT <t>              Data time interval in sec, or decimate input data [REQUIRED] ()
#
## Pseudorange solution (PRS) configuration:
# --PRSniter <n>        PRS: Limit on number of iterations (10)
# --PRSconverge <cl>    PRS: Convergence limit in m (3.00e-07)
# --PRSrmsLimit <rms>   PRS: RMS residual limit in m (6.50)
# --PRSslopeLimit <sl>  PRS: RAIM residual limit in m (0.00)
# --PRSMinElev <elev>   PRS: Reject data below elevation <elev> degrees (10.00)
#
## Output files:
# --OutPath <dir>       Path for output files ()
# --RAWFileOut <file>   Filename for output of raw data ()
# --PRSFileOut <file>   Filename for output of pseudorange solution ()
# --CLKFileOut <file>   Filename for output of Rx clock bias and model ()
# --RDDFileOut <file>   Filename for output of raw DD data ()
# --DDDFileOut <file>   Filename for output of (edited) DD data ()
# --TDDFileOut <file>   Filename for output of triple difference data ()
# --DDRFileOut <file>   Filename for output of DD post-fit residuals ()
#
## Output misc:
# --BaseOut <id-id,x,y,z> Baseline to output; <id>s are station labels, '-' is
#                          required, <x,y,z> are optional baseline coordinates
#                          for comparison [repeatable] ()
# --validate            Read input and validate it, then quit (don't)
#


###############################################################################
# @todo - DiscFix: Check that -h/--help is handled properly
###############################################################################
#add_test(NAME DiscFix_CmdOpt_help
#         COMMAND ${CMAKE_COMMAND}
#         -DTEST_PROG=$<TARGET_FILE:DiscFix>
#         -DSOURCEDIR=${GPSTK_TEST_DATA_DIR}
#         -DTARGETDIR=${GPSTK_TEST_OUTPUT_DIR}
#         -P ${CMAKE_SOURCE_DIR}/core/tests/testhelp.cmake)

##############################################################################
# @todo - DiscFix: Check that all other command line options are handled properly
###############################################################################