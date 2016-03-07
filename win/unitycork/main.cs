using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
//using System.Threading.Tasks;

namespace unitycork
{


    //class CorkTriMeshHandler
    //{
    //    // handle into unmanaged memory, for an unmanaged object
    //    IntPtr _h;

    //    // performs some operation on h
    //    [DllImport ( "dllcork2" )]
    //    static extern void OperateOnHandle ( IntPtr h );

    //    // frees resources of h
    //    [DllImport ( "dllcork2" )]
    //    static extern void DeleteHandle ( IntPtr h );

    //    ~CorkTriMeshHandler ()
    //    {
    //        DeleteHandle ( _h );
    //    }

    //    CorkTriMeshHandler(IntPtr handle )
    //    {
    //        this._h = handle;
    //    }


    //    public void m ()
    //    {
    //        OperateOnHandle ( _h );
    //        // no further references to _handle
    //    }
    //}


    public class PluginImport 
    {


        //Lets make our calls from the Plugin
        [DllImport ( "dllcork2", EntryPoint = "addition" )]
        public static extern float addition ( float val_1, float val_2 );


        [DllImport ( "dllcork2" )]
        private static extern bool createTriMesh ( float[] vertices_1, int n_vertices1, uint[] faces_1, int n_faces_1, out IntPtr item );

        //Lets make our calls from the Plugin
        [DllImport ( "dllcork2")]
        private static extern bool compute_union ( float[] vertices_1, int n_vertices1, uint[] faces_1, int n_faces_1,
                                                   float[] vertices_2, int n_vertices2, uint[] faces_2, int n_faces_2, out IntPtr item );

        [DllImport ( "dllcork2" )]
        private static extern uint GetNbVertices ( IntPtr h );

        [DllImport ( "dllcork2" )]
        private static extern float substraction ( float val_1, float val_2 );
        [DllImport ( "dllcork2" )]
        private static extern float multiplication ( float val_1, float val_2 );
        [DllImport ( "dllcork2" )]
        private static extern float division ( float val_1, float val_2 );


        


        public static void Start ()
        {
            //{ 0.0f,0.0f,0.0f, 1.0f,0.0f,0.0f, 0.0f,1.0f,0.0f};
            float[] vertices1 = {1f, 1f, 1f, -1f, 1f, 1f, -1f, -1f, 1f, 1f, -1f, 1f, 1f, -1f, -1f, 1f, 1f, -1f, -1f, 1f, -1f, -1f, -1f, -1f };
            //{ 0.0f,0.0f,0.0f, 1.0f,0.0f,0.0f, 1.0f,1.0f,0.0f};
            float[] vertices2 = {0.5f+1f, 0.5f+1f, 0.5f+1f, 0.5f-1f, 0.5f+1f, 0.5f+1f, 0.5f-1f, 0.5f-1f, 0.5f+1f, 0.5f+ 1f, 0.5f-1f, 0.5f+1f, 0.5f+1f, 0.5f-1f, 0.5f-1f, 0.5f+ 1f, 0.5f+1f, 0.5f-1f, 0.5f-1f, 0.5f+1f, 0.5f-1f, 0.5f-1f, 0.5f-1f, 0.5f-1f };

            int nb_vertices = 8;            
            uint[] faces = { 0,1,2, 0,2,3,  0,3,4, 0,4,5,  0,5,6, 0,6,1,
                             1,6,7, 1,7,2,  7,4,3, 7,3,2,  4,7,6, 4,6,5};
            uint[] faces2 = { 0,1,2, 0,2,3,  0,3,4, 0,4,5,  0,5,6, 0,6,1,
                             1,6,7, 1,7,2,  7,4,3, 7,3,2,  4,7,6, 4,6,5};
            int nb_faces = 12;

            IntPtr handle = IntPtr.Zero;

            Debug.Print ( createTriMesh ( vertices1, nb_vertices, faces, nb_faces, out handle ).ToString () );
            Debug.Print ( GetNbVertices ( handle ).ToString () );

            Debug.Print (  compute_union ( vertices1, nb_vertices, faces, nb_faces, 
                            vertices2, nb_vertices, faces2, nb_faces, out handle ).ToString() );

            Debug.Print ( GetNbVertices ( handle).ToString () );

            var i = addition ( 5, 5 );
            Debug.Print ( addition ( 5, 5 ).ToString() );
            Debug.Print ( substraction ( 10, 5 ).ToString () );
            Debug.Print ( multiplication ( 2, 5 ).ToString () );
            Debug.Print ( division ( 10, 2 ).ToString () );
        }
    }
}


