#include <cuda_runtime.h>
#include <stdio.h>

void getFreeMemory(size_t* free_mem, size_t* total_mem){
  cudaError_t result = cudaMemGetInfo(free_mem, total_mem);
  if (result != cudaSuccess) {
    printf("error during getFreeMemory call\n");
  }
}

int main(){
  size_t free_mem  = 0;
  size_t total_mem = 0;

  getFreeMemory(&free_mem, &total_mem);
  printf("Total Memory Available: %f Mb\n", static_cast<float>(total_mem)/(1024.0*1024.0));
  printf("Free Memory Available: %f Mb\n", static_cast<float>(free_mem)/(1024.0*1024.0));
  printf("Memory ratio: %f Mb\n", static_cast<float>(free_mem)/static_cast<float>(total_mem));
}