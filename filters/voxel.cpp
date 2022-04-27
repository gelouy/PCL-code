/*
* 体素下采样
*/
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/filters/voxel_grid.h>

using namespace std;

pcl::PointCloud<pcl::PointXYZ>::Ptr pcl_filter_voxel(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_in, float leaf_size)
{
    pcl::VoxelGrid<pcl::PointXYZ> voxel_grid;
    voxel_grid.setLeafSize(leaf_size, leaf_size, leaf_size);
    voxel_grid.setInputCloud(cloud_in);
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out(new pcl::PointCloud<pcl::PointXYZ>());
    voxel_grid.filter(*cloud_out);

    return cloud_out;
}

//test------------//
int main(int argc, char** argv)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::io::loadPCDFile(argv[1],*cloud);

    auto cloud_out = pcl_filter_voxel(cloud,1);

    cout << "采样前点数：" << cloud->size() << endl;
    cout << "采样后点数：" << cloud_out->size() << endl;

    system("pause");
    return 0;

}
