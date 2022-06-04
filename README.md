# check-for-your-privilege

This repository contains code written for my CS109 challenge project, "Check for Your Privilege." There are two components:
* A library for calculating probability using a Bayesian network with rejection sampling
  * Base class is in model/include/model.h
  * Subclasses are used to define the probabilities for individual models, such as model/include/SeattleModel.h
  * I ended up not using this because I decided to focus on conditional probabilities, but thought I'd include the code anyway
* Jupyter notebook for processing [Public Use Microdata Sample](https://www.census.gov/programs-surveys/acs/microdata.html) data from the 2019 American Community Survey
  * Reads in data and adds flags for factors of interest
  * Runs logistic regressions on data
  * Summarizes group counts
  * Exports group counts data to CSV for use in Observable via SQLite
