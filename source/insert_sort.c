void insert_sort(int* arr, int len)
{
  for (int i = 1; i < len; i++)
  {
    int hold = arr[i];
    int j = i;
    while ((j > 0) && hold < arr[j - 1])
    {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = hold;
  }
}