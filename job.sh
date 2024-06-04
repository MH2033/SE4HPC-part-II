#!/bin/bash
#SBATCH --job-name=matrix_mul ## Name of the job
#SBATCH -e stderr.out ## Name of the error file
#SBATCH -o stdout.out ## Name of the output file
#SBATCH --time=05:00 ## Job Duration
#SBATCH --ntasks=1 ## Number of tasks (analyses) to run
#SBATCH --cpus-per-task=2 ## The number of threads the code will use
#SBATCH --mem-per-cpu=1024M ## Real memory(MB) per CPU required by the job.

srun singularity run -C matrix_mult_cont.sif
