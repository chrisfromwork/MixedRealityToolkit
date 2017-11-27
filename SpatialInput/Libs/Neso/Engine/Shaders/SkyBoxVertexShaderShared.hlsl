
VSOutput main( float4 pos : POSITION0, uint instanceId : SV_InstanceID )
{
    VSOutput output;

    const uint id = instanceId % 2;

    output.pos = pos;

    float4 texPos = mul(pos, InverseViewProjection[id]);

    output.tex = texPos.xyz / texPos.w;

    output.ViewId = id;

    return output;
}