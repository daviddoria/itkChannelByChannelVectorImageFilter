#include <itkVectorImage.h>
#include <itkImage.h>
#include <itkAbsImageFilter.h>
#include "itkChannelByChannelVectorImageFilter.h"
#include "itkImageFileWriter.h"

typedef itk::VectorImage<double, 2> VectorImageType;

void CreateImage(VectorImageType::Pointer image);

int main(int, char*[])
{
  
  typedef itk::Image<double, 2> ScalarImageType;
  typedef itk::AbsImageFilter<ScalarImageType, ScalarImageType> AbsFilterType;
  typedef itk::ChannelByChannelVectorImageFilter<VectorImageType, AbsFilterType> ChannelByChannelType;
  
  VectorImageType::Pointer image = VectorImageType::New();
  CreateImage(image);
  
  ChannelByChannelType::Pointer channelByChannelFilter = ChannelByChannelType::New();
  channelByChannelFilter->SetInput(image);
  channelByChannelFilter->Update();
  
  typedef  itk::ImageFileWriter< VectorImageType  > WriterType;
  WriterType::Pointer writer = WriterType::New();
  writer->SetFileName("output.mhd");
  writer->SetInput(channelByChannelFilter->GetOutput());
  writer->Update();
  return EXIT_SUCCESS;
}

 
void CreateImage(VectorImageType::Pointer image)
{
  VectorImageType::IndexType start;
  start.Fill(0);
 
  VectorImageType::SizeType size;
  size.Fill(100);
 
  VectorImageType::RegionType region(start,size); 
 
  image->SetRegions(region);
  image->SetNumberOfComponentsPerPixel(2);
  image->Allocate();
  
  typedef itk::VariableLengthVector<double> VariableVectorType;
  VariableVectorType variableLengthVector;
  variableLengthVector.SetSize(2);
  variableLengthVector[0] = -1.1;
  variableLengthVector[1] = 2.2;
  
  image->FillBuffer(variableLengthVector);
 
}