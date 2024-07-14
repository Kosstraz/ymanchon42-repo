# TEST WITH NO PARAMETERS
./aristote

# REPEAT TEST
./aristote [count]

# TEST WITH SPECIFIC TESTS (replace '_' by ' ')
DOESN'T WORK                                                                                    <br />
---./aristote ["5_800_200_200"] ["4_410_200_200"] ["4_310_200_100"] ...---

# TEST WITH FULL PARAMETERS
./aristote [count] ["5_800_200_200_7"] ["6_610_300_200"] ...


======================================


# CONFIGURATION :
cd [your_project_dir]											<br />
git clone git@github.com:Kosstraz/ARISTOTE.git					<br />
cd ARISTOTE														<br />
make															<br />
ENJOY YOUR CRASHES :)

# MODIFICATION(S) :
Modify [WAITNG_TIME] in includes/Aristote.h if you want to
wait longer for each test (don't forget to make).				<br />
Change [TEST_DEFAULTx] in includes/Aristote.h if you want to 
do other tests quicker, instead of creating more tests 
yourself (don't forget to make)

# !IMPORTANT! for MODIFICATION(S) part
if a philosopher dies, and ARISTOTE doesn't see him, 
the [EMERCY_TIME] will be added to the timer 
in order to give dup2 more time to duplicate the fd and ARISTOTE 
more time to detect the death.