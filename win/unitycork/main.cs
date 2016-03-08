using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
//using System.Threading.Tasks;

namespace unitycork
{

    public class PluginImport 
    {


        [DllImport ( "dllcork2" )]
        private static extern bool CreateTriMesh ( float[] vertices_1, uint n_vertices1, uint[] faces_1, uint n_faces_1, int target );

        //Lets make our calls from the Plugin
        [DllImport ( "dllcork2")]
        private static extern bool ComputeUnion ( );

        //========== getting data out of the current mesh

        [DllImport ( "dllcork2" )]
        private static extern uint GetNbVertices ( );

        [DllImport ( "dllcork2" )]
        private static extern uint GetNbFaces ();

        [DllImport ( "dllcork2" )]
        private static extern IntPtr GetFaces ( out uint size );

        [DllImport ( "dllcork2" )]
        private static extern IntPtr GetVertices ( out uint size );


        [DllImport ( "dllcork2" )]
        private static extern void RemoveIntList ( IntPtr array );

        [DllImport ( "dllcork2" )]
        private static extern void RemoveFloatList ( IntPtr array );

        //==========         

        public static float[] GetVerticesList ()
        {
            float[] result = null;
            uint size;

            IntPtr arrayValue = IntPtr.Zero;
            try
            {
                arrayValue = GetVertices ( out size );
                if ( arrayValue != IntPtr.Zero )
                {
                    result = new float[size];
                    Marshal.Copy ( arrayValue, result, 0, Convert.ToInt32 ( size ) );
                }
            }
            finally
            {
                // don't forget to free the list
                RemoveFloatList ( arrayValue );
            }

            return result;
        }

        public static int[] GetFaceList ()
        {
            int[] result = null;
            uint size;

            IntPtr arrayValue = IntPtr.Zero;
            try
            {
                arrayValue = GetFaces ( out size );
                if ( arrayValue != IntPtr.Zero )
                {
                    result = new int[size];
                    Marshal.Copy ( arrayValue, result, 0, Convert.ToInt32(size) );
                }
            }
            finally
            {
                // don't forget to free the list
                RemoveIntList ( arrayValue );
            }

            return result;
        }


        public static void Start ()
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
            int target = 1;
            CreateTriMesh ( vertices1, nb_vertices, faces, nb_faces, target );

            // create the second mesh
            target = 2;
            CreateTriMesh ( vertices2, nb_vertices, faces2, nb_faces, target );

            // do the op
            ComputeUnion ();

            // get the result values
            Debug.Print ( GetNbVertices ( ).ToString () );            

            var array0 = GetFaceList();
            foreach ( var item in array0 )
            {
                Console.WriteLine ( item.ToString () );
            }

            var array = GetVerticesList ();
            foreach ( var item in array )
            {
                Console.WriteLine ( item.ToString () );
            }
           
        }
    }
}


