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
            //float[] vertices1 = {1f, 1f, 1f, -1f, 1f, 1f, -1f, -1f, 1f, 1f, -1f, 1f, 1f, -1f, -1f, 1f, 1f, -1f, -1f, 1f, -1f, -1f, -1f, -1f };
            ////{ 0.0f,0.0f,0.0f, 1.0f,0.0f,0.0f, 1.0f,1.0f,0.0f};
            //float[] vertices2 = {0.5f+1f, 0.5f+1f, 0.5f+1f, 0.5f-1f, 0.5f+1f, 0.5f+1f, 0.5f-1f, 0.5f-1f, 0.5f+1f, 0.5f+ 1f, 0.5f-1f, 0.5f+1f, 0.5f+1f, 0.5f-1f, 0.5f-1f, 0.5f+ 1f, 0.5f+1f, 0.5f-1f, 0.5f-1f, 0.5f+1f, 0.5f-1f, 0.5f-1f, 0.5f-1f, 0.5f-1f };

            //uint nb_vertices = 8;
            //uint[] faces = { 0,1,2, 0,2,3,  0,3,4, 0,4,5,  0,5,6, 0,6,1,
            //                 1,6,7, 1,7,2,  7,4,3, 7,3,2,  4,7,6, 4,6,5};
            //uint[] faces2 = { 0,1,2, 0,2,3,  0,3,4, 0,4,5,  0,5,6, 0,6,1,
            //                 1,6,7, 1,7,2,  7,4,3, 7,3,2,  4,7,6, 4,6,5};
            //uint nb_faces = 12;

            // create the first mesh         
            //int target = 1;
            //CorkGateway.SendMesh ( vertices1, nb_vertices, faces, nb_faces, target );

            // create the second mesh
            //target = 2;
            //CorkGateway.SendMesh ( vertices2, nb_vertices, faces2, nb_faces, target );

            // data from unity
            //System.Single[] vertices0 = new System.Single[] {  1.850372E-17, -3.700744E-17, 1, 1, -3.700744E-17, 1, 1, 1, 1, 1.850372E-17, 1, 1, 1, 1, 5.551115E-17, 0, 1, 5.551115E-17, 1, 5.551115E-17, -5.551115E-17, 0, 5.551115E-17, -5.551115E-17};

            System.Single[] vertices0 = new System.Single[] { 1.850372E-17f, -3.700744E-17f, 1f, 1f, -3.700744E-17f, 1f, 1f, 1f, 1f, 1.850372E-17f, 1f, 1f, 1f, 1f, 5.551115E-17f, 0f, 1f, 5.551115E-17f, 1f, 5.551115E-17f, -5.551115E-17f, 0f, 5.551115E-17f, -5.551115E-1f };
            //System.UInt32[] faces0 = new System.UInt32[] {0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7, 8, 9, 10, 8, 10, 11, 12, 13, 14, 12, 14, 15, 16, 17, 18, 16, 18, 19, 20, 21, 22, 20, 22, 23 };
            UInt32[] faces0  = new System.UInt32[] { 0, 1, 2, 0, 2, 3, 3, 2, 4, 3, 4, 5, 5, 4, 6, 5, 6, 7, 7, 6, 1, 7, 1, 0, 1, 6, 4, 1, 4, 2, 7, 0, 3, 7, 3, 5 };
            //uint[] faces2 = { 0,1,2, 0,2,3,  0,3,4, 0,4,5,  0,5,6, 0,6,1,
            //                 1,6,7, 1,7,2,  7,4,3, 7,3,2,  4,7,6, 4,6,5};

            CorkGateway.SendMesh ( vertices0, Convert.ToUInt32 ( vertices0.Length ), faces0, Convert.ToUInt32 ( faces0.Length )/3, 1 );


            System.Single[] vertices1 = { -0.5f, -0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, 0.5f, 0.5f, 0.5f, 0.5f, -0.5f, -0.5f, 0.5f, -0.5f, 0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f};
            //System.UInt32[] faces1    = new System.UInt32[] { 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7, 8, 9, 10, 8, 10, 11, 12, 13, 14, 12, 14, 15, 16, 17, 18, 16, 18, 19, 20, 21, 22, 20, 22, 23 };
            UInt32[] faces1  = new System.UInt32[] { 0, 1, 2, 0, 2, 3, 3, 2, 4, 3, 4, 5, 5, 4, 6, 5, 6, 7, 7, 6, 1, 7, 1, 0, 1, 6, 4, 1, 4, 2, 7, 0, 3, 7, 3, 5 };

            CorkGateway.SendMesh ( vertices1, Convert.ToUInt32 ( vertices1.Length ), faces1, Convert.ToUInt32 ( faces1.Length )/3, 2 );



            // do the op
            try { 
            CorkGateway.ExecuteBooleanOp ( "union" );
            CorkGateway.ExecuteBooleanOp ( "difference" );
            CorkGateway.ExecuteBooleanOp ( "intersection" );
            CorkGateway.ExecuteBooleanOp ( "symetric_difference" );
            }
            catch {

            }

            // get the result values            

            var array0 = CorkGateway.GetFaceList();
            Console.WriteLine ( string.Join ( ", ", array0.Select ( i => i.ToString () ).ToArray () ) );


            var array = CorkGateway.GetVerticesList ();
            Console.WriteLine ( string.Join ( ", ", array.Select ( i => i.ToString () ).ToArray () ) );
            
            Console.ReadKey ();
        }
    }
}
