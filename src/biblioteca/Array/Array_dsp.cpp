
#include <Pds/Array>
#include <cmath>



// Instantiate Pds::Array for the supported template type parameters
template class Pds::Array<double>;
template class Pds::Array<unsigned char>;
template class Pds::Array<unsigned int >;

template <class Datum>
Pds::Array<Datum> Pds::Array<Datum>::FilterMean3(void) const
{
    if(this->IsEmpty()) return Pds::Array<Datum>();
    unsigned int Nlin=this->nlin;
    unsigned int Ncol=this->ncol;
    unsigned int Nlin1=Nlin-1;
    unsigned int Ncol1=Ncol-1;
    unsigned int lin,col;
    
    Pds::Array<Datum> Ans(Nlin,Ncol);
    double S=0;
    
    for(lin=1;lin<Nlin1;lin++)
    for(col=1;col<Ncol1;col++)
    {
        S=0;
        S+=this->array[lin-1][col-1];
        S+=this->array[lin-1][col  ];
        S+=this->array[lin-1][col+1];
        S+=this->array[lin  ][col-1];
        S+=this->array[lin  ][col  ];
        S+=this->array[lin  ][col+1];
        S+=this->array[lin+1][col-1];
        S+=this->array[lin+1][col  ];
        S+=this->array[lin+1][col+1];
        
        Ans.array[lin][col]=S/9;
    }

    for(col=0;col<Ncol;col++)
    {
        Ans.array[0    ][col]=this->array[0    ][col];
        Ans.array[Nlin1][col]=this->array[Nlin1][col];
    }
    for(lin=0;lin<Nlin;lin++)
    {
        Ans.array[lin][0    ]=this->array[lin][0    ];
        Ans.array[lin][Ncol1]=this->array[lin][Ncol1];
    }
    return Ans;
}

template <class Datum>
Pds::Array<Datum> Pds::Array<Datum>::FilterMean3b(void) const
{
    if(this->IsEmpty()) return Pds::Array<Datum>();
    unsigned int Nlin=this->nlin;
    unsigned int Ncol=this->ncol;
    unsigned int Nlin1=Nlin-1;
    unsigned int Ncol1=Ncol-1;
    unsigned int lin,col;
    
    Pds::Array<Datum> Ans(Nlin,Ncol);
    double S=0;
    
    for(lin=1;lin<Nlin1;lin++)
    for(col=1;col<Ncol1;col++)
    {
        S=0;
        S+=this->array[lin-1][col-1];
        S+=this->array[lin-1][col  ];
        S+=this->array[lin-1][col+1];
        S+=this->array[lin  ][col-1];
        S+=this->array[lin  ][col  ]*2;
        S+=this->array[lin  ][col+1];
        S+=this->array[lin+1][col-1];
        S+=this->array[lin+1][col  ];
        S+=this->array[lin+1][col+1];
        
        Ans.array[lin][col]=S/10;
    }

    for(col=0;col<Ncol;col++)
    {
        Ans.array[0    ][col]=this->array[0    ][col];
        Ans.array[Nlin1][col]=this->array[Nlin1][col];
    }
    for(lin=0;lin<Nlin;lin++)
    {
        Ans.array[lin][0    ]=this->array[lin][0    ];
        Ans.array[lin][Ncol1]=this->array[lin][Ncol1];
    }
    return Ans;
}

////////////////////////////////////////////////////////////////////////////////
template <class Datum>
Datum RescaleRawPseudoTrilinear(Datum **array,double lin,double col, double factor)
{
    unsigned int Ll=floor(lin);
    unsigned int Lc=floor(col);
    unsigned int Hl=ceil(lin);
    unsigned int Hc=ceil(col);
    
    double alpha=col-floor(col);
    double beta=lin-floor(lin);

    double P1=array[Ll][Lc];
    double P2=array[Ll][Hc];
    double P3=array[Hl][Lc];
    double P4=array[Hl][Hc];

    double S1,S2;

    S2 = (1.0-beta)*(1.0-alpha)*P1+
         (1.0-beta)*(    alpha)*P2+
         (    beta)*(1.0-alpha)*P3+
         (    beta)*(    alpha)*P4;

    S1=(P1+P2+P3+P4)/4.0;

    return (S1*(factor-1)+S2*(2-factor));
}

template <class Datum>
Pds::Array<Datum> Pds::Array<Datum>::Resize(double factor) const
{
    if(this->IsEmpty()) return Pds::Array<Datum>();
    if(factor<1.0)      return Pds::Array<Datum>();
    if(factor>2.0)      return Pds::Array<Datum>();

    unsigned int Nlin2=(this->Nlin())/factor;
    unsigned int Ncol2=(this->Ncol())/factor;
    double flin=this->Nlin()/(1.0*Nlin2);
    double fcol=this->Ncol()/(1.0*Ncol2);

    unsigned int lin,col;
    Pds::Array<Datum> R(Nlin2,Ncol2);
    
    for(lin=0;lin<Nlin2;lin++)
    for(col=0;col<Ncol2;col++)
    {
        R.array[lin][col]=RescaleRawPseudoTrilinear(this->array,flin*lin,fcol*col,factor);
    }    
    return R;
}

