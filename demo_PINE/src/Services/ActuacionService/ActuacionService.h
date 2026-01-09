#ifndef ACTUACION_SERVICE_H
#define ACTUACION_SERVICE_H

#include "../../Models/Actuacion/Actuacion.h"
#include "../Repository/Repository.h"

class ActuacionService
{
    private:
        Repository<Actuacion>* repo;

    public:
        explicit ActuacionService(Repository<Actuacion>* _repo) :
            repo(_repo)
        {}
};

#endif // !ACTUACION_SERVICE_H
