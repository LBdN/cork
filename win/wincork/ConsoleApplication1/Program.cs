using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;

using unitycork;

namespace ConsoleApplication1
{
    class Program
    {
        

        static void Main ( string[] args )
        {


            //{ 0.0f,0.0f,0.0f, 1.0f,0.0f,0.0f, 0.0f,1.0f,0.0f};
            float[] vertices1 = {1f, 1f, 1f, -1f, 1f, 1f, -1f, -1f, 1f, 1f, -1f, 1f, 1f, -1f, -1f, 1f, 1f, -1f, -1f, 1f, -1f, -1f, -1f, -1f };
            //{ 0.0f,0.0f,0.0f, 1.0f,0.0f,0.0f, 1.0f,1.0f,0.0f};
            float[] vertices2 = {0.5f+1f, 0.5f+1f, 0.5f+1f, 0.5f-1f, 0.5f+1f, 0.5f+1f, 0.5f-1f, 0.5f-1f, 0.5f+1f, 0.5f+ 1f, 0.5f-1f, 0.5f+1f, 0.5f+1f, 0.5f-1f, 0.5f-1f, 0.5f+ 1f, 0.5f+1f, 0.5f-1f, 0.5f-1f, 0.5f+1f, 0.5f-1f, 0.5f-1f, 0.5f-1f, 0.5f-1f };

            uint nb_vertices = 8;
            uint[] faces = { 0,1,2, 0,2,3,  0,3,4, 0,4,5,  0,5,6, 0,6,1,
                             1,6,7, 1,7,2,  7,4,3, 7,3,2,  4,7,6, 4,6,5};
            uint[] faces2 = { 0,1,2, 0,2,3,  0,3,4, 0,4,5,  0,5,6, 0,6,1,
                             1,6,7, 1,7,2,  7,4,3, 7,3,2,  4,7,6, 4,6,5};
            uint nb_faces = 12;

            // create the first mesh

            System.UInt32[]faces0 = new System.UInt32[36] {0u, 1u, 2u, 0u, 2u, 3u, 4u, 5u, 6u, 4u, 6u, 7u, 8u, 9u, 10u, 8u, 10u, 11u, 12u, 13u, 14u, 12u, 14u, 15u, 16u, 17u, 18u, 16u, 18u, 19u, 20u, 21u, 22u, 20u, 22u, 23u};

            System.Single[] vertices0 = new System.Single[72] { -0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, -0.5f };


            int target = 1;
            CorkGateway.SendMesh ( vertices0, Convert.ToUInt32 ( vertices0.Length ), faces0, Convert.ToUInt32 ( faces0.Length ), target );
            //CorkGateway.SendMesh ( vertices1, nb_vertices, faces, nb_faces, target );

            // create the second mesh
            target = 2;
            CorkGateway.SendMesh ( vertices2, nb_vertices, faces2, nb_faces, target );

            // do the op
            CorkGateway.ExecuteBooleanOp ( "union" );
            CorkGateway.ExecuteBooleanOp ( "difference" );
            CorkGateway.ExecuteBooleanOp ( "intersection" );
            CorkGateway.ExecuteBooleanOp ( "symetric_difference" );

            // get the result values            

            var array0 = CorkGateway.GetFaceList();
            Console.WriteLine ( string.Join ( ", ", array0.Select ( i => i.ToString () ).ToArray () ) );


            var array = CorkGateway.GetVerticesList ();
            Console.WriteLine ( string.Join ( ", ", array.Select ( i => i.ToString () ).ToArray () ) );
            
            Console.ReadKey ();
        }
    }
}
